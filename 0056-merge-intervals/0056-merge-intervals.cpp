class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int start1 = 0;
        int end1 = 0;
        int start2 = 0;
        int end2 = 0;

        sort(intervals.begin(), intervals.end());

        int p1 = 0;
        int p2 = 1;

        while (p1 < intervals.size()) {
            start1 = intervals[p1][0];
            end1 = intervals[p1][1];
            
            if (p2 == intervals.size()) {
                ans.push_back({start1, end1});
                p1++;
                continue;
            }
            
            start2 = intervals[p2][0];
            end2 = intervals[p2][1];

            int new_st = 0;
            int new_en = 0;

            if (end1 >= end2) {
                // Keep extending end1 using p2 until no overlap
                new_st = start1;
                new_en = end1;
                while (p2 < intervals.size() && new_en >= intervals[p2][0]) {
                    new_en = max(new_en, intervals[p2][1]);
                    p2++;
                }
                ans.push_back({new_st, new_en});
                p1 = p2;
                p2 = p1 + 1;
            }
            else if (end1 >= start2) {
                // Overlap found: expand new_en as far right as possible
                new_st = start1;
                new_en = end2;
                while (p2 < intervals.size() && new_en >= intervals[p2][0]) {
                    new_en = max(new_en, intervals[p2][1]);
                    p2++;
                }
                ans.push_back({new_st, new_en});
                p1 = p2;
                p2 = p1 + 1;
            }
            else {
                new_st = start1;
                new_en = end1;
                ans.push_back({new_st, new_en});
                p1++;
                p2++;
            }
        }

        return ans;
    }
};