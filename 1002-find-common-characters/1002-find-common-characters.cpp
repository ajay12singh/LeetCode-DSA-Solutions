class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> prev(26, 0);
        vector<int> curr(26, 0);

        string current = words[0];

        for (int i = 0; i < current.length(); i++) {
            prev[current[i] - 'a']++;
        }

        for (int i = 1; i < words.size(); i++) {
            curr.assign(26, 0);
            current = words[i];

            for (int j = 0; j < current.length(); j++) { 
                curr[current[j] - 'a']++;
            }

            for (int k = 0; k < 26; k++) {
                prev[k] = min(prev[k], curr[k]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (prev[i] > 0) {
                res.push_back(string(1, i + 'a'));
                prev[i]--;
            }
        }

        return res;
    }
};