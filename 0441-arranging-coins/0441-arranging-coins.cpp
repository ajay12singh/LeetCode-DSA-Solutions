class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        int mid;
       long long  int diff=-1;
       int ans = -1;
        while(low <= high ){
            mid =  low+(high - low)/2;

            diff= n -(long long)mid*(mid+1)/2;
            if(diff>=0){
                ans = mid;
                low = mid+1;
            } 
            else{
                high = mid -1;
            }
        }
        return ans;
        
    }
};