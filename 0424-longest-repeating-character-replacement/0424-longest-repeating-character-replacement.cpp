class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {
            // 1. Add current character to window frequency
            freq[s[j] - 'A']++;
            
            // 2. Track highest frequency of ANY single character currently in window
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // 3. (Window size - maxFreq) gives required replacements.
            // If replacements needed > k, shrink window from left
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            // 4. Update answer with current valid window size
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};