class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int p1 = 0;
        int p2 = 1;

        while (p1 < intervals.size()) {
            int start1 = intervals[p1][0];
            int end1 = intervals[p1][1];
            
            if (p2 == intervals.size()) {
                ans.push_back({start1, end1});
                p1++;
                continue;
            }

            int start2 = intervals[p2][0];

            // Single check: if end1 >= start2, there IS an overlap
            if (end1 >= start2) {
                int new_st = start1;
                int new_en = end1;
                
                while (p2 < intervals.size() && new_en >= intervals[p2][0]) {
                    new_en = max(new_en, intervals[p2][1]);
                    p2++;
                }
                
                ans.push_back({new_st, new_en});
                p1 = p2;
                p2 = p1 + 1;
            }
            else {
                ans.push_back({start1, end1});
                p1++;
                p2++;
            }
        }

        return ans;
    }
};