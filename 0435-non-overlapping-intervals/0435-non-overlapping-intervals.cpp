class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int ans = 0;

        int p1 = 0 ; 
        int p2 = 1;
        
        sort(intervals.begin(),intervals.end());

        int min_end  = intervals[p1][1]; 


         while(p2 < intervals.size()){

            if(p2<intervals.size() && min_end>intervals[p2][0]){
                ans++;
                min_end = min(min_end,intervals[p2][1]);
                p1 = p2;
            
                p2++;

            }

            else {
                min_end = max(min_end,intervals[p2][1]);
                
                p2++;

            }
         }

         return ans;
        
    }
};