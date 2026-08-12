class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1) return 0;
        int i = 0;
        int j = 0;

        long long int ans = 0;
        long long int product = 1;

        while(j<nums.size()){

            product = (long long)product * nums[j];

           

            while(product>=k ){

                product = product/nums[i];
        
                i++;


            }
              
            ans += j-i+1;
            j++;
           

        }
        return ans;
        
    }
};