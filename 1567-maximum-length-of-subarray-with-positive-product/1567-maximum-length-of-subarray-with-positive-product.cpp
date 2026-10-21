class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        int first_neg = -1;  
        int reset = -1;   
        int neg_count = 0;  

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                reset = i;
                first_neg = -1;
                neg_count = 0;
            }
            else {
                if (nums[i] < 0) {
                    neg_count++;
                    if (first_neg == -1) {
                        first_neg = i;
                    }
                }

                
                if (neg_count % 2 == 0) {
                    max_len = max(max_len, i - reset);
                } 
                
                else {
                    max_len = max(max_len, i - first_neg);
                }
            }
        }

        return max_len;
    }
};