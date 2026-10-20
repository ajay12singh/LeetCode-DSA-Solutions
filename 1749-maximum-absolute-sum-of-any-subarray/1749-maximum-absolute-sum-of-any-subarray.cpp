class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        if(nums.size() == 1) {
            return abs(nums[0]);
        }

        int curr_sum = 0;

        int max_sum = 0;

        int curr_min_sum  = 0;

        for(int i = 0 ; i< nums.size() ; i++){

            curr_min_sum = min(curr_min_sum + nums[i],nums[i]);


            curr_sum = max(curr_sum +nums[i] , nums[i]);

            int maxi =max(abs(curr_sum),abs(curr_min_sum)) ;

            max_sum = max(max_sum,maxi );

        }

        return max_sum ;
        
    }
};