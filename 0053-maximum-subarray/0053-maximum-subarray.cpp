class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        // vector<int> cum_sum(nums.size());

        // cum_sum[0]  = nums[0];

        if(nums.size() == 1) return nums[0];

        int cum_sum = nums[0];

        int ans = INT_MIN;


        for(int i = 1 ;  i < nums.size() ; i++){

             ans = max(ans,cum_sum ); 
             
            if(cum_sum < 0 )  cum_sum = 0;

            cum_sum += nums[i];

            ans = max(ans,cum_sum );

        }

        return ans;
        
    }
};