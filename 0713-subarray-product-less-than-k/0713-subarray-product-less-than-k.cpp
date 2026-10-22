class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {


        if(k <= 1) return 0;

        int product = 1;

        int ans = 0;

       int i = 0 ;
       int j = 0;

       while(j<nums.size()){

        product *= nums[j];

        

        

        while(i<=j && product > k){

            product = product/nums[i];
            i++;
           

       }
        if(product<k) ans += j-i+1;
       j++;


       }

    return ans;
    }
};