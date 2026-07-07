class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int maxPairSum = 0;
        
        
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            maxPairSum = max(maxPairSum, currentSum);
            left++;
            right--;
        }
        
        return maxPairSum;
    }
};