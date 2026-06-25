class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for(int i = 0;i < nums.size();i++){
            low = max(low,nums[i]);
            high +=nums[i];
        }
        int ans = high ;
        while(low<=high){
            int mid = low+(high-low)/2;
                int count=1;
                int sum = 0;
            for(int i = 0;i<nums.size();i++){
                if(mid>=sum+nums[i]){
                    sum+=nums[i];
                }
                else{
                    sum = nums[i];
                    count++;
                }
            }
            if(count>k){
                low = mid+1;

            }
            else {
                ans = mid;
                high = mid-1;
            }
        }

       return ans; 
        
    }
};