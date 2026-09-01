#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:

    int kadaneMax(std::vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
        return max_sum;
    }

    int kadaneMin(std::vector<int>& nums) {
        int min_sum = nums[0];
        int current_sum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            current_sum = std::min(nums[i], current_sum + nums[i]);
            min_sum = std::min(min_sum, current_sum);
        }
        return min_sum;
    }

public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
     
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);

        int max_kadane = kadaneMax(nums);
        int min_kadane = kadaneMin(nums);
            
        int circular_sum = total_sum - min_kadane;

       
        if (max_kadane < 0) {
            return max_kadane;
        }

          return std::max(max_kadane, circular_sum);
    }
};