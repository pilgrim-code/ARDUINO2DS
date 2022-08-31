from everywhereml.data import ImageDataset
from everywhereml.data.collect import MjpegCollector

base_folder = 'boards_over_http'

try:
    # if our dataset folder already exists, load it
    image_dataset = ImageDataset.from_nested_folders(
        name='Boards', 
        base_folder=base_folder
    )
except FileNotFoundError:
    # if the dataset folder does not exists, collect the samples
    # from the Esp32-cam web server
    # duration is how long (in seconds) the program will collect 
    # the images for each class
    mjpeg_collector = MjpegCollector(address='http://192.168.1.149')
    image_dataset = mjpeg_collector.collect_many_classes(
        dataset_name='Boards', 
        base_folder=base_folder,
        duration=40
    )




print(image_dataset)

"""
Display a preview of the captured images
"""
image_dataset.preview(
    samples_per_class=10, 
    rows_per_class=2, 
    figsize=(20, 10)
)


"""
Image classification with HOG works on grayscale images at the moment
So convert images to grayscale in the range 0-255
"""
image_dataset = image_dataset.gray().uint8()

"""
Preview grayscale images
"""
image_dataset.preview(
    samples_per_class=10, 
    rows_per_class=2, 
    figsize=(20, 10), 
    cmap='gray'
)


"""
Create an object detection pipeline with HOG feature extractor
"""
from everywhereml.preprocessing.image.object_detection import HogPipeline
from everywhereml.preprocessing.image.transform import Resize

pipeline = HogPipeline(
    transforms=[
        Resize(width=40, height=30)
    ]
)

# Convert images to feature vectors
feature_dataset = pipeline.fit_transform(image_dataset)
feature_dataset.describe()


"""
Print pipeline description
"""
print(pipeline)



"""
Create and fit RandomForest classifier
"""
from everywhereml.sklearn.ensemble import RandomForestClassifier

clf = RandomForestClassifier(n_estimators=8, max_depth=40)

# fit on train split and get accuracy on the test split
train, test = feature_dataset.split(test_size=0.4)
clf.fit(train)

print('Score on test set: %.2f' % clf.score(test))

# now fit on the whole dataset
clf.fit(feature_dataset)

print("COPIA EL MODELO DESDE ACA:   ")

print(clf.to_arduino_file(
    filename='path-to-sketch/HogClassifier.h',
    instance_name='classifier', 
    class_map=feature_dataset.class_map
))

print("FIN DEL MODELO A C++")


print("COPIA EL PIPELINE DESDE ACA: ")

print(pipeline.to_arduino_file(
    filename='HogPipeline.h',
    instance_name='hog'
))


print("FIN DEL PIPELINE")


