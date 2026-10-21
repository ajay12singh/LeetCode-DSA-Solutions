class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int best_ans = 0 ;
        int i = 0;
        int best_i = values[i]+i;
        

        for(int j = 1 ; j < values.size() ; j++)
        {   
            best_ans = max(best_ans,best_i + values[j]-j);

            best_i = max(best_i,values[j] + j );

        
        }

        return best_ans;


        
    }
};