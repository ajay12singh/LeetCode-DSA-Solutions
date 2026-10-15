class Solution {
public:
    typedef long long ll;

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        // Find the maximum index to define the size of the difference array
        int maxR = 0;
        for (auto& seg : segments) {
            maxR = max(maxR, seg[1]);
        }

        // diff array to store color changes
        // boundary array to mark start/end points of painting segments
        vector<ll> diff(maxR + 2, 0);
        vector<bool> boundary(maxR + 2, false);

        for (auto& seg : segments) {
            int start = seg[0];
            int end   = seg[1];
            int color = seg[2];

            diff[start] += color;
            diff[end]   -= color;

            boundary[start] = true;
            boundary[end]   = true;
        }

        vector<vector<ll>> result;
        ll currentSum = 0;
        ll prevIndex = -1;

        // Sweep through the difference array
        for (int i = 0; i <= maxR; i++) {
            if (boundary[i]) {
                if (currentSum > 0) {
                    result.push_back({prevIndex, i, currentSum});
                }
                prevIndex = i;
            }
            currentSum += diff[i];
        }

        return result;
    }
};