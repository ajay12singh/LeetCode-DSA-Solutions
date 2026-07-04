class Solution {
public:
    int findKthNumber(int m, int n, int k) {

        long long int low = 1;
        long long int high = m*n;

        int mid;
        int ans = high;

        while (low <= high ){
            mid = low +(high - low )/2;

            int count = 0;
            for (int i = 1; i <= m;i++){
                count+=min(mid/i,n);
            }
            if(count>=k){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
     return ans;
         }
};