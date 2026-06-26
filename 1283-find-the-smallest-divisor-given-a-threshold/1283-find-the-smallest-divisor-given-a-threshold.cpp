class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i  <  nums.size() ; i++){
            
             high = max(high,nums[i]);
           
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i = 0 ; i < nums.size();i++){

                
                    

                    if (nums[i]%mid == 0){
                        sum+= nums[i]/mid;
                    }
                    else{
                        sum+=nums[i]/mid+1;
                    }
                
            }
            if(sum<=threshold){
                ans = mid;
                high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};