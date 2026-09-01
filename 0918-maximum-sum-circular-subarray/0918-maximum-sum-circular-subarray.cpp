class Solution {
private:
    int kadaneMax(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = 0;

        for (int x : nums) {
            current_sum += x;
            if (current_sum > max_sum) max_sum = current_sum;
            if (current_sum < 0) current_sum = 0; 
        }
        return max_sum;
    }

    int kadaneMin(vector<int>& nums) {
        int min_sum = nums[0];
        int current_sum = 0;

        for (int x : nums) {
            current_sum += x;
            if (current_sum < min_sum) min_sum = current_sum;
            if (current_sum > 0) current_sum = 0; 
        }
        return min_sum;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        for (int x : nums) total_sum += x;

        int max_kadane = kadaneMax(nums);
        int min_kadane = kadaneMin(nums);

        if (max_kadane < 0) return max_kadane;

        int circular_sum = total_sum - min_kadane;
        return max_kadane > circular_sum ? max_kadane : circular_sum;
    }
};