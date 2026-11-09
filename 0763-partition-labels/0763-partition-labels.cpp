#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        // Step 1: Record the LAST index of each character
        std::unordered_map<char, int> last_idx;
        for (int i = 0; i < s.size(); i++) {
            last_idx[s[i]] = i;
        }

        std::vector<int> res;
        int p1 = 0;
        int p2 = 0;
        int maxi = 0;

        // Step 2: Traverse with two pointers matching your logic
        while (p2 < s.size()) {
            // Expand the partition boundary to include the last position of s[p2]
            maxi = std::max(maxi, last_idx[s[p2]]);

            // When p2 reaches the maximum required boundary for all characters seen so far
            if (p2 == maxi) {
                res.push_back(p2 - p1 + 1); // Save partition size
                p1 = p2 + 1;                // Move start pointer to the next partition
            }
            
            p2++;
        }

        return res;
    }
};