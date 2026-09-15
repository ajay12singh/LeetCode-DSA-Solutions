

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Clean spaces and reverse whole string
        int read = 0, write = 0, n = s.length();
        
        while (read < n) {
            while (read < n && s[read] == ' ') read++; // Skip extra spaces
            if (read < n) {
                if (write > 0) s[write++] = ' '; // Insert single space separator
                while (read < n && s[read] != ' ') {
                    s[write++] = s[read++];
                }
            }
        }
        s.resize(write); // Remove trailing space memory

        reverse(s.begin(), s.end()); // Reverse entire cleaned string

        // Step 2: Your word-by-word reversal logic
        int i = 0, j = 0, k = 0;
        int len = s.length();

        while (j < len) {
            // Find the end of the current word
            while (j < len && s[j] != ' ') {
                j++;
            }
            
            k = j - 1; // Last character of the current word

            // Reverse the individual word using your two-pointer swap
            while (i < k) {
                swap(s[i], s[k]);
                i++;
                k--;
            }

            // Move pointers to start of next word
            j++; 
            i = j;
        }

        return s;
    }
};