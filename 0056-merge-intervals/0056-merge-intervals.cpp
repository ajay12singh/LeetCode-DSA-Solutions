class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            // If ans is empty OR no overlap with the last added interval
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } 
            // Overlap detected: extend the end of the last added interval
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};