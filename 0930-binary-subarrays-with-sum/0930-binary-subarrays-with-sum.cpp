class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        

        unordered_map<int,int> sum;

        int i = 0;
        int j = 0;

        int current_sum = 0;
        sum[current_sum]++;
        int result = 0;

        while(j<nums.size())
        {
            current_sum+=nums[j];

           

            if(sum.count(current_sum - goal)){

                result+=sum[current_sum - goal];

            }
             sum[current_sum]++;
            j++;
        }

        return result;
    }
};