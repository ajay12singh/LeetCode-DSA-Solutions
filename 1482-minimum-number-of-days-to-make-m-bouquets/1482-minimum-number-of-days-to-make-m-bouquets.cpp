class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { 
        
        int low = 0;
        int ans = -1;
        int high = 0;
        long long total_needed=(long long)m * k;
        for(int  i = 0 ; i < bloomDay.size();i++){
            low = min(low,bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        if(bloomDay.size() < total_needed ) return -1;


        while(low<=high){
            int mid = low+(high-low)/2;

            int count_k = 0;
            int count_m = 0;
            for(int i = 0;i<bloomDay.size();i++){

                if(mid>=bloomDay[i] ){
                   count_k++;
                   if(count_k == k ) {
                    count_k = 0 ;
                    count_m++;
                   }


                   
                }
               
                else {
                    count_k = 0;
                }
            }
            if(count_m < m){
                  low = mid+1;

            }
            else{
                ans = mid;
                high = mid-1;
              
                
            }
        }
    return ans ;

    }
};