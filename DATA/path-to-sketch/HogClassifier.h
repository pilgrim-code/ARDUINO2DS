#ifndef UUID2184573686600
#define UUID2184573686600

/**
  * RandomForestClassifier(base_estimator=DecisionTreeClassifier(), bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'min_impurity_split', 'random_state', 'ccp_alpha'), max_depth=40, max_features=auto, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_impurity_split=None, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=8, n_jobs=None, num_outputs=3, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
    uint16_t votes[3] = { 0 };
    uint8_t classIdx = 0;
    float classScore = 0;

    
        tree0(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree1(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree2(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree3(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree4(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree5(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree6(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    
        tree7(x, &classIdx, &classScore);
        votes[classIdx] += classScore;
    

    // return argmax of votes
uint8_t maxClassIdx = 0;
float maxVote = votes[0];

for (uint8_t i = 1; i < 3; i++) {
    if (votes[i] > maxVote) {
        maxClassIdx = i;
        maxVote = votes[i];
    }
}

predictedValue = maxClassIdx;


            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }


        

/**
 * Predict class label
 */
String predictLabel(float *x) {
    return getLabelOf(predict(x));
}

/**
 * Get label of last prediction
 */
String getLabel() {
    return getLabelOf(lastPrediction);
}

/**
 * Get label of given class
 */
String getLabelOf(int8_t idx) {
    switch (idx) {
        case -1:
            return "ERROR";
        
            case 0:
                return "Keys";
        
            case 1:
                return "Lukas";
        
            case 2:
                return "NOCHE";
        
        default:
            return "UNKNOWN";
    }
}


        /**
 * Get latency in micros
 */
uint32_t latencyInMicros() {
    return latency;
}

/**
 * Get latency in millis
 */
uint16_t latencyInMillis() {
    return latency / 1000;
}

    protected:
        float latency = 0;
        int lastPrediction = 0;

        

    
        
            /**
             * Random forest's tree #0
             */
            void tree0(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[9] <= 0.04919292777776718) {
        
            
    if (x[89] <= 0.23735081404447556) {
        
            
    *classIdx = 0;
    *classScore = 1270.0;
    return;

        
    }
    else {
        
            
    if (x[90] <= 0.1683904305100441) {
        
            
    *classIdx = 1;
    *classScore = 31.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 611.0;
    return;

        
    }

        
    }

        
    }
    else {
        
            
    if (x[106] <= 0.16269025951623917) {
        
            
    *classIdx = 2;
    *classScore = 611.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 31.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #1
             */
            void tree1(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[116] <= 0.9630981981754303) {
        
            
    if (x[53] <= 0.8708190023899078) {
        
            
    *classIdx = 1;
    *classScore = 28.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1243.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 641.0;
    return;

        
    }

            }
        
    
        
            /**
             * Random forest's tree #2
             */
            void tree2(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[26] <= 0.077844999730587) {
        
            
    if (x[132] <= 0.08464741706848145) {
        
            
    *classIdx = 0;
    *classScore = 1267.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 25.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[16] <= 0.015007289592176676) {
        
            
    *classIdx = 2;
    *classScore = 620.0;
    return;

        
    }
    else {
        
            
    if (x[97] <= 0.06111413985490799) {
        
            
    *classIdx = 1;
    *classScore = 25.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 620.0;
    return;

        
    }

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #3
             */
            void tree3(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[110] <= 0.12503989040851593) {
        
            
    if (x[60] <= 0.006014526356011629) {
        
            
    if (x[69] <= 0.14407827518880367) {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }
    else {
        
            
    if (x[87] <= 0.00506313843652606) {
        
            
    *classIdx = 1;
    *classScore = 31.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1209.0;
    return;

        
    }

        
    }

        
    }
    else {
        
            
    if (x[45] <= 0.13990816846489906) {
        
            
    *classIdx = 0;
    *classScore = 1209.0;
    return;

        
    }
    else {
        
            
    if (x[100] <= 0.15977932885289192) {
        
            
    *classIdx = 1;
    *classScore = 31.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (x[27] <= 0.014916381100192666) {
        
            
    if (x[90] <= 0.17934349924325943) {
        
            
    if (x[97] <= 0.04615146294236183) {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }
    else {
        
            
    if (x[88] <= 0.15216419473290443) {
        
            
    *classIdx = 0;
    *classScore = 1209.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }

        
    }

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[86] <= 0.00790449045598507) {
        
            
    *classIdx = 1;
    *classScore = 31.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 672.0;
    return;

        
    }

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #4
             */
            void tree4(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[7] <= 0.07716698199510574) {
        
            
    if (x[88] <= 0.028289790265262127) {
        
            
    if (x[37] <= 0.018986089155077934) {
        
            
    *classIdx = 1;
    *classScore = 39.0;
    return;

        
    }
    else {
        
            
    if (x[21] <= 0.0035138287348672748) {
        
            
    *classIdx = 0;
    *classScore = 1251.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 622.0;
    return;

        
    }

        
    }

        
    }
    else {
        
            
    if (x[67] <= 0.15051403641700745) {
        
            
    *classIdx = 2;
    *classScore = 622.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1251.0;
    return;

        
    }

        
    }

        
    }
    else {
        
            
    if (x[25] <= 0.11779168248176575) {
        
            
    *classIdx = 0;
    *classScore = 1251.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 39.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #5
             */
            void tree5(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[63] <= 0.08128654584288597) {
        
            
    if (x[116] <= 0.7914394438266754) {
        
            
    if (x[36] <= 0.02808251604437828) {
        
            
    *classIdx = 1;
    *classScore = 41.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1195.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 676.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[53] <= 0.9009251892566681) {
        
            
    if (x[83] <= 0.005314220208674669) {
        
            
    if (x[12] <= 0.03693093731999397) {
        
            
    *classIdx = 2;
    *classScore = 676.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 41.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 676.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1195.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #6
             */
            void tree6(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[89] <= 0.09211185202002525) {
        
            
    *classIdx = 0;
    *classScore = 1262.0;
    return;

        
    }
    else {
        
            
    if (x[26] <= 0.9611892402172089) {
        
            
    *classIdx = 1;
    *classScore = 33.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 617.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #7
             */
            void tree7(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[9] <= 0.04919292777776718) {
        
            
    if (x[82] <= 0.006562419235706329) {
        
            
    if (x[42] <= 0.2701471447944641) {
        
            
    *classIdx = 1;
    *classScore = 32.0;
    return;

        
    }
    else {
        
            
    *classIdx = 2;
    *classScore = 611.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1269.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[105] <= 0.13514206930994987) {
        
            
    *classIdx = 2;
    *classScore = 611.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 32.0;
    return;

        
    }

        
    }

            }
        
    


};



static RandomForestClassifier classifier;


#endif