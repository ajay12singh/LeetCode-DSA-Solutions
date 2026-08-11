class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> array(260, 0);
        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < s.length()) {
            array[s[j]]++;

            // Shrink window from the left until s[j] is no longer a duplicate
            while (array[s[j]] > 1) {
                array[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};