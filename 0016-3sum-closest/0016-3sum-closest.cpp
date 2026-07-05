class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int p2 = i + 1;
            int p3 = n - 1;
            
            while (p2 < p3) {
                int currentSum = nums[i] + nums[p2] + nums[p3];
                
                if (currentSum == target) {
                    return currentSum;
                }
                
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    p2++;
                    while (p2 < p3 && nums[p2] == nums[p2 - 1]) p2++;
                } else {
                    p3--;
                    while (p2 < p3 && nums[p3] == nums[p3 + 1]) p3--;
                }
            }
        }
        return closestSum;
    }
};