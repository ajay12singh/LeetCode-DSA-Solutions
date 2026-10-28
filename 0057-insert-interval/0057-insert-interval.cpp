class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int p1 = 0;
        int n = intervals.size();

        // 1. Add all intervals that end before newInterval starts (no overlap)
        while (p1 < n && intervals[p1][1] < newInterval[0]) {
            res.push_back(intervals[p1]);
            p1++;
        }

        // 2. Merge all overlapping intervals with newInterval
        while (p1 < n && intervals[p1][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[p1][0]);
            newInterval[1] = max(newInterval[1], intervals[p1][1]);
            p1++;
        }
        res.push_back(newInterval);

        // 3. Add remaining intervals after newInterval
        while (p1 < n) {
            res.push_back(intervals[p1]);
            p1++;
        }

        return res;
    }
};