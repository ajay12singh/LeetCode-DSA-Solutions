class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }

        
        int max_gain1 = 0, current_gain1 = 0;
        for (int i = 0; i < n; i++) {
            int diff1 = nums2[i] - nums1[i];
            current_gain1 = max(0, current_gain1 + diff1);
            max_gain1 = max(max_gain1, current_gain1);
        }

        
        int max_gain2 = 0, current_gain2 = 0;
        for (int i = 0; i < n; i++) {
            int diff2 = nums1[i] - nums2[i];
            current_gain2 = max(0, current_gain2 + diff2);
            max_gain2 = max(max_gain2, current_gain2);
        }

        return max(sum1 + max_gain1, sum2 + max_gain2);
    }
};