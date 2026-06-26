class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long sum_dif = 0;
        int n = nums1.size();
        
        // 1. Calculate the initial sum of absolute differences
        for(int i = 0; i < n; i++) {
            sum_dif += abs(nums1[i] - nums2[i]);
        }

        // 2. Sort a copy of nums1 to use binary search
        vector<int> sorted1 = nums1;
        sort(sorted1.begin(), sorted1.end());

        long long max_gain = 0;

        // 3. For each nums2[i], find the best replacement in nums1
        for(int i = 0; i < n; i++) {
            int original_diff = abs(nums1[i] - nums2[i]);
            
            // lower_bound finds the first element >= nums2[i]
            auto it = lower_bound(sorted1.begin(), sorted1.end(), nums2[i]);
            
            // Check the element >= nums2[i]
            if(it != sorted1.end()) {
                max_gain = max(max_gain, (long long)original_diff - abs(*it - nums2[i]));
            }
            
            // Check the element < nums2[i] (the one before 'it')
            if(it != sorted1.begin()) {
                max_gain = max(max_gain, (long long)original_diff - abs(*prev(it) - nums2[i]));
            }
        }
        
        // 4. Subtract the biggest gain from the initial sum
        return (sum_dif - max_gain) % 1000000007;
    }
};