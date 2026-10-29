#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort balloons by their END coordinates
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int arrow_pos = points[0][1]; // Shoot first arrow at the end of the first balloon

        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts AFTER the arrow position, we need a new arrow
            if (points[i][0] > arrow_pos) {
                arrows++;
                arrow_pos = points[i][1]; // Update arrow position to the end of this balloon
            }
        }

        return arrows;
    }
};