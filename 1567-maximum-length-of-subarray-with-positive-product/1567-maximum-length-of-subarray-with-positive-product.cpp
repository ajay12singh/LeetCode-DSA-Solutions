class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        // Pass 1: Left to Right (Handles dropping up to first negative)
        int neg_count = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                neg_count = 0;
                len = 0;
            } else {
                if (nums[i] < 0) neg_count++;
                len++;
                if (neg_count % 2 == 0) {
                    max_len = max(max_len, len);
                }
            }
        }

        // Pass 2: Right to Left (Handles dropping from last negative onwards)
        neg_count = 0;
        len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                neg_count = 0;
                len = 0;
            } else {
                if (nums[i] < 0) neg_count++;
                len++;
                if (neg_count % 2 == 0) {
                    max_len = max(max_len, len);
                }
            }
        }

        return max_len;
    }
};