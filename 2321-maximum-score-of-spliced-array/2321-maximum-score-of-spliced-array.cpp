class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        vector<int> cum_sum(nums1.size());
        vector<int> cum_sum2(nums2.size());

        
        cum_sum[0] = nums1[0];
        for(int i = 1 ; i < cum_sum.size() ; i++){
            cum_sum[i] = cum_sum[i-1] + nums1[i];
        }

        cum_sum2[0] = nums2[0];
        for(int i = 1 ; i < cum_sum2.size() ; i++){
            cum_sum2[i] = cum_sum2[i-1] + nums2[i];
        }

        int total1 = cum_sum.back();
        int total2 = cum_sum2.back();

        
        int max_gain1 = 0, current_gain1 = 0;
        for (int r = 0; r < nums1.size(); r++) {
            current_gain1 = max(0, current_gain1 + (nums2[r] - nums1[r]));
            max_gain1 = max(max_gain1, current_gain1);
        }

      
        int max_gain2 = 0, current_gain2 = 0;
        for (int r = 0; r < nums2.size(); r++) {
            current_gain2 = max(0, current_gain2 + (nums1[r] - nums2[r]));
            max_gain2 = max(max_gain2, current_gain2);
        }

        return max(total1 + max_gain1, total2 + max_gain2);
    }
};