class Solution {
public:
   int maxProduct(vector<int>& nums) {
    int max_prod = nums[0];
    int store_prod = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        
        if (nums[i] < 0) {
            swap(max_prod, store_prod);
        }

        
        max_prod = max(nums[i], max_prod * nums[i]);
        store_prod = min(nums[i], store_prod * nums[i]);

        
        ans = max(ans, max_prod);    
    }

    return ans;
}
};