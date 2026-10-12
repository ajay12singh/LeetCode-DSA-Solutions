class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        if(target.size() == 1) return target[0];
        int ans = 0;

        for(int i = 1; i < target.size(); i++ ){

            if(target[i]>target[i-1]) ans += target[i]-target[i-1];

        }
        return ans+target[0];
    }
};