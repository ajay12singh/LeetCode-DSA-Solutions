class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> result;

        while (p1 < firstList.size() && p2 < secondList.size()) {
            // Find the start and end of the intersection
            int start = max(firstList[p1][0], secondList[p2][0]);
            int end = min(firstList[p1][1], secondList[p2][1]);

            // If it's a valid intersection, add it
            if (start <= end) {
                result.push_back({start, end});
            }

            // Move the pointer of the interval that finishes earlier
            if (firstList[p1][1] < secondList[p2][1]) {
                p1++;
            } else {
                p2++;
            }
        }

        return result;
    }
};