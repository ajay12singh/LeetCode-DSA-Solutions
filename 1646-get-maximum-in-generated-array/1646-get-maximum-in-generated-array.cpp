class Solution {
public:
    int getMaximumGenerated(int n) {


        vector<int> nums(n+1);

        if(n==0 ) return 0;
        if(n==1) return 1;


        nums[0] = 0;
        nums[1] = 1;
        int ans = 0;

        for(int i = 0 ; i <= n/2 ; i++){

            nums[2*i] = nums[i];
            if(2*i + 1 <=  n ){
                nums[2*i + 1 ] = nums[i] + nums[i+1];
                int maxi = max(nums[2*i] ,nums[2*i+1]);
                ans = max(ans,maxi);
            }


            // ans = max(ans,nums[2*i],nums[2*i+1]);


        }

         
        return ans;
    }
};