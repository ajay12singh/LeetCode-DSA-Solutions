class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            // If ans is empty or current interval doesn't overlap with the last merged one
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } 
            // Overlap found: update the end of the last merged interval
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        
        return ans;
    }
};