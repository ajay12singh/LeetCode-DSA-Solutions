class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int neg_count = 0;

        int ans = 0 ;
        int  start = 0;
        int first_neg = -1;
       
        

        for(int i = 0 ; i < nums.size() ; i++){


            if(nums[i] == 0) {

                start = i+1;
                neg_count = 0;
                first_neg = -1;

            }

            if((nums[i]< 0)){

                neg_count++;
                if(first_neg == -1) first_neg = i;
                if(neg_count%2 ==0) ans = max(ans,i-start+1);

                else ans = max(ans,i-first_neg);


            }

            else{


                if(neg_count%2 == 0)
                 ans = max(ans,i-start+1);
                else {
                 ans = max(ans,i-first_neg);
                }
            }



        }

        return ans;
        
    }
};