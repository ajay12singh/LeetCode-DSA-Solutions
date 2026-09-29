class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;

        int i = 0; 
        int j = needle.size() - 1;
        int p1 = 0; 
        int p2 = needle.size() - 1;

        while (j < haystack.size()) {
            
            if (haystack[i] == needle[p1] && haystack[j] == needle[p2]) {
                
            
                if (haystack.substr(i, needle.size()) == needle) {
                    return i; 
                }
            }
            
            
            i++;
            j++;
        }

        return -1;
    }
};