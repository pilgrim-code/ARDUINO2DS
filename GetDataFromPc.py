# Opens the inbuilt camera of laptop to capture video.
from multiprocessing.connection import wait
import cv2
cap = cv2.VideoCapture(0)
i = 0
 
while(cap.isOpened()):
    ret, frame = cap.read()
   
     
    # This condition prevents from infinite looping
    # incase video ends.
    if ret == False:
        break
     
    # Save Frame by Frame into disk using imwrite method
    cv2.imwrite('DATA/Frame'+str(i)+'.jpg', frame)
    i+=1
    
    if (i+1)%500==0:
        break
 
cap.release()
cv2.destroyAllWindows()