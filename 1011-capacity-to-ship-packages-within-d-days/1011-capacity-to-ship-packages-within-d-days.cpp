class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i = 0;i<weights.size();i++){
            maxi= max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low = maxi;
        int high = sum;
        int mid;
        int ans = sum;
        while(low<=high){
            mid=low+(high-low)/2;
            int sum = 0;
            int day=1;
            for(int i = 0;i<weights.size();i++){
                int current_weights = weights[i];
                if(mid>=sum + current_weights){
                    sum+=current_weights;
                    
                }
                else {
                    sum = current_weights;
                    day++;
                    
                }
            }
            if(day<=days){
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