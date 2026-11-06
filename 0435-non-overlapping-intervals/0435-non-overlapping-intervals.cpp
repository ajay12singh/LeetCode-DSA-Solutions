class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int ans = 0;

     
        int p2 = 1;
        
        sort(intervals.begin(),intervals.end());

        int prev_end  = intervals[0][1]; 


         while(p2 < intervals.size()){

            while(p2<intervals.size() && prev_end>intervals[p2][0]){
                ans++;
                prev_end = min(prev_end,intervals[p2][1]);
            
            
                p2++;

            }

            while(p2<intervals.size() && prev_end<=intervals[p2][0]) {
                prev_end = max(prev_end,intervals[p2][1]);
                
                p2++;

            }
         }

         return ans;
        
    }
};