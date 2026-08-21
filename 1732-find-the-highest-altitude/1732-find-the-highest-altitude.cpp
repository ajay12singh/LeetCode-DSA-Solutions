class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int max_gain = 0;

        vector<int> prefix_gain(gain.size()+1,0);

       
        for(int i = 0; i < gain.size(); i++){

            prefix_gain[i+1] = prefix_gain[i]+ gain[i];
            max_gain = max(prefix_gain[i+1],max_gain);

        }

        return max_gain;
        
    }
};