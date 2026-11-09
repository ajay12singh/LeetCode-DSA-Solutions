#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Start point (negative height)
            events.push_back({b[1], b[2]});  // End point (positive height)
        }

        // Sort points by x-coordinate; tie-breaking is handled by negative/positive heights
        sort(events.begin(), events.end());

        vector<vector<int>> res;
        multiset<int> activeHeights = {0}; // Track current active heights
        int prevMax = 0;

        for (const auto& [x, h] : events) {
            if (h < 0) {
                activeHeights.insert(-h); // Building starts
            } else {
                activeHeights.erase(activeHeights.find(h)); // Building ends
            }

            int currentMax = *activeHeights.rbegin();
            // If the max height changes, we found a key skyline point
            if (currentMax != prevMax) {
                res.push_back({x, currentMax});
                prevMax = currentMax;
            }
        }

        return res;
    }
};