class Solution {
public:
    int largestVariance(string s) {
        // Track presence of each character ('a' through 'z') in the string
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch - 'a'] = 1;
        }

        int result = 0;

        // Iterate over all possible pairs of characters (first and second)
        for(char first = 'a'; first <= 'z'; first++) {
            for(char second = 'a'; second <= 'z'; second++) {

                // Skip if either character is not present in string 's'
                if(count[first - 'a'] == 0 || count[second - 'a'] == 0) {
                    continue;
                }

                int firstCount = 0;   // Frequency of 'first' character
                int secondCount = 0;  // Frequency of 'second' character

                bool pastSecond = false; // Tracks if 'second' was encountered in the past

                for(char &ch : s) {
                    if(ch == first) {
                        firstCount++;
                    }
                    if(ch == second) {
                        secondCount++;
                    }

                    // If 'second' character appears at least once in the current substring
                    if(secondCount > 0) {
                        result = max(result, firstCount - secondCount);
                    } 
                    // If 'second' character is 0 in current substring but was seen previously
                    else if(pastSecond == true) {
                        result = max(result, firstCount - 1);
                    }

                    // Kadane's algorithm variation: Reset counters if secondCount exceeds firstCount
                    if(secondCount > firstCount) {
                        firstCount = 0;
                        secondCount = 0;
                        pastSecond = true; // Mark that 'second' character was seen in past
                    }
                }
            }
        }

        return result;
    }
};