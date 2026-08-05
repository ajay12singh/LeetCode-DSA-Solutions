class Solution {
    bool allzero(vector<int>& map) {
        for (int &i : map) {
            if (i != 0) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> result;
        if (n < m) return result;

        vector<int> map(26, 0);
        for (int i = 0; i < m; i++) {
            map[p[i] - 'a']++;
            map[s[i] - 'a']--;
        }

        if (allzero(map)) {
            result.push_back(0);
        }

        for (int i = m; i < n; i++) {
            map[s[i] - 'a']--;
            map[s[i - m] - 'a']++;
            if (allzero(map)) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};