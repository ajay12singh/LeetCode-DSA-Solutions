class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int total_interval = 0;
        int count = 0;

        for (int i = 0; i < intervals.size(); i++) {
            total_interval += 1;
        }

        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int prev_st = intervals[0][0];
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (prev_end < intervals[i][1]) {
                prev_st = intervals[i][0];
                prev_end = intervals[i][1];
            }
            else {
                count++;
            }
        }
        return total_interval - count;
    }
};