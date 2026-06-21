class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        // Create a vector of pairs (score, original_index)
        std::vector<std::pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({score[i], i});
        }

        // Sort based on scores in descending order
        std::sort(pairs.rbegin(), pairs.rend());

        std::vector<std::string> result(n);
        for (int i = 0; i < n; ++i) {
            int originalIndex = pairs[i].second;
            if (i == 0) {
                result[originalIndex] = "Gold Medal";
            } else if (i == 1) {
                result[originalIndex] = "Silver Medal";
            } else if (i == 2) {
                result[originalIndex] = "Bronze Medal";
            } else {
                result[originalIndex] = std::to_string(i + 1);
            }
        }
        
        return result;
    }
};