#ifndef UUID2704585682760
#define UUID2704585682760

/**
  * RandomForestClassifier(base_estimator=DecisionTreeClassifier(), bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'min_impurity_split', 'random_state', 'ccp_alpha'), max_depth=40, max_features=auto, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_impurity_split=None, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=8, n_jobs=None, num_outputs=2, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
    uint16_t votes[2] = { 0 };
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

for (uint8_t i = 1; i < 2; i++) {
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
                return "Key";
        
            case 1:
                return "Lukas";
        
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
                
    if (x[62] <= 0.39847296476364136) {
        
            
    if (x[99] <= 0.0018034384120255709) {
        
            
    if (x[93] <= 0.01438959501683712) {
        
            
    *classIdx = 1;
    *classScore = 1804.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1122.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1122.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[120] <= 0.27692532166838646) {
        
            
    *classIdx = 1;
    *classScore = 1804.0;
    return;

        
    }
    else {
        
            
    if (x[90] <= 0.17979864589869976) {
        
            
    *classIdx = 1;
    *classScore = 1804.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1122.0;
    return;

        
    }

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #1
             */
            void tree1(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[62] <= 0.3798358738422394) {
        
            
    if (x[34] <= 0.017010008916258812) {
        
            
    *classIdx = 1;
    *classScore = 1806.0;
    return;

        
    }
    else {
        
            
    if (x[13] <= 0.1522393450140953) {
        
            
    if (x[87] <= 0.003620457835495472) {
        
            
    if (x[34] <= 0.21395444124937057) {
        
            
    *classIdx = 1;
    *classScore = 1806.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1120.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1120.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[4] <= 0.23716433346271515) {
        
            
    *classIdx = 1;
    *classScore = 1806.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1120.0;
    return;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 1806.0;
    return;

        
    }

            }
        
    
        
            /**
             * Random forest's tree #2
             */
            void tree2(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[11] <= 0.20882683247327805) {
        
            
    if (x[86] <= 0.6742332428693771) {
        
            
    *classIdx = 1;
    *classScore = 1758.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1168.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[17] <= 0.26726987957954407) {
        
            
    *classIdx = 0;
    *classScore = 1168.0;
    return;

        
    }
    else {
        
            
    if (x[112] <= 0.7575619220733643) {
        
            
    *classIdx = 1;
    *classScore = 1758.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1168.0;
    return;

        
    }

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #3
             */
            void tree3(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[27] <= 0.561786562204361) {
        
            
    *classIdx = 0;
    *classScore = 1135.0;
    return;

        
    }
    else {
        
            
    if (x[90] <= 0.1815837398171425) {
        
            
    if (x[31] <= 0.5168045312166214) {
        
            
    *classIdx = 1;
    *classScore = 1791.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1135.0;
    return;

        
    }

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1135.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #4
             */
            void tree4(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[46] <= 0.2746543437242508) {
        
            
    *classIdx = 1;
    *classScore = 1742.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1184.0;
    return;

        
    }

            }
        
    
        
            /**
             * Random forest's tree #5
             */
            void tree5(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[45] <= 0.26706257462501526) {
        
            
    if (x[90] <= 0.28409258276224136) {
        
            
    *classIdx = 1;
    *classScore = 1811.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1115.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[4] <= 0.05166297405958176) {
        
            
    if (x[81] <= 0.016911549493670464) {
        
            
    *classIdx = 1;
    *classScore = 1811.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1115.0;
    return;

        
    }

        
    }
    else {
        
            
    if (x[17] <= 0.597346767783165) {
        
            
    *classIdx = 0;
    *classScore = 1115.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 1811.0;
    return;

        
    }

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #6
             */
            void tree6(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[46] <= 0.23604193329811096) {
        
            
    *classIdx = 1;
    *classScore = 1766.0;
    return;

        
    }
    else {
        
            
    if (x[15] <= 0.3015279918909073) {
        
            
    *classIdx = 0;
    *classScore = 1160.0;
    return;

        
    }
    else {
        
            
    *classIdx = 1;
    *classScore = 1766.0;
    return;

        
    }

        
    }

            }
        
    
        
            /**
             * Random forest's tree #7
             */
            void tree7(float *x, uint8_t *classIdx, float *classScore) {
                
    if (x[27] <= 0.5648007988929749) {
        
            
    *classIdx = 0;
    *classScore = 1147.0;
    return;

        
    }
    else {
        
            
    if (x[3] <= 0.8626320362091064) {
        
            
    *classIdx = 1;
    *classScore = 1779.0;
    return;

        
    }
    else {
        
            
    *classIdx = 0;
    *classScore = 1147.0;
    return;

        
    }

        
    }

            }
        
    


};



static RandomForestClassifier classifier;


#endif