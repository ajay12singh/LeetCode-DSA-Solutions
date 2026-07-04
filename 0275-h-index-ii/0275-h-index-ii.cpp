class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0 ;
        int high = citations.size()-1;

        int ans = 0;
        int  mid ; 
         int quality ;
          int count ;
          
        while(low<=high){
            mid = low + ( high - low)/2;
            
            quality =  citations[mid];
            count = citations.size() - mid;
            if( quality >= count) {
                ans = count;
               high = mid-1;
            }
            else{
                    low = mid+1;            }    
        }
        
        return ans;
    }
};