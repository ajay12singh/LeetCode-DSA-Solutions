class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int ans = -1;
        
        vector<int> prefix(nums.size());
        prefix[0] = 0;

        for(int i = 1; i < nums.size();i++){

            prefix[i] =prefix[i-1] + nums[i-1];

        }

        vector<int> suffix(nums.size());

        suffix[nums.size()-1] = 0;

        for(int i = nums.size()-2; i >= 0 ; i--){
            suffix[i] = suffix[i+1] + nums[i+1];
        }

        for(int i = 0 ; i < nums.size();i++){

            if(prefix[i] == suffix[i]){
                 ans=i;
                 break;
            }

        }
        
        return ans;
    }
};