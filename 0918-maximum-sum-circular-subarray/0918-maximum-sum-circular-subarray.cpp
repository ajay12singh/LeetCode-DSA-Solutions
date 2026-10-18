class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {


        long long int total_sum = 0; 
        long long int max_sum  = INT_MIN ;

        long long int curr_sum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            total_sum += nums[i];

            curr_sum += nums[i];
            max_sum= max(max_sum , curr_sum );

            if(curr_sum < 0) curr_sum = 0 ;
            

        }

        if(max_sum < 0 ) return max_sum ;

        curr_sum = 0;
        long long int  min_sum  = INT_MAX; 

        for(int i = 0 ; i < nums.size() ; i++){

            curr_sum += nums[i];
            min_sum = min(min_sum , curr_sum );

            if(curr_sum > 0) curr_sum = 0 ;
            

        }


    return max(max_sum,total_sum-min_sum);        
    }
};