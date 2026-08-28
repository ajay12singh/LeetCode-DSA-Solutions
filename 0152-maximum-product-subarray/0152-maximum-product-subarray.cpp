class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int left_product = 1;
        int  right_product = 1;
        int ans = nums[0];

        for (int i = 0; i < n; i++) {
           
            if (left_product == 0) left_product = 1;
            if (right_product == 0) right_product = 1;

            left_product *= nums[i];
            right_product *= nums[n - 1 - i];

            ans = max(ans, max(left_product, right_product));
        }

        return ans;
    }
};