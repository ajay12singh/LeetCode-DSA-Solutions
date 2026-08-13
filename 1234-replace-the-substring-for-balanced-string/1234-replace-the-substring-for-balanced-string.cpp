class Solution {
public:
    int balancedString(string s) {
    int n = s.length();
    int k = n / 4;
    unordered_map<char, int> count;
    
    for (char c : s) count[c]++;
    
    // Check if already balanced
    if (count['Q'] <= k && count['W'] <= k && 
        count['E'] <= k && count['R'] <= k) {
        return 0;
    }
    
    int min_len = n;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        count[s[right]]--; // Remove character from outside frequency count
        
        // Shrink window while frequencies outside window are valid
        while (left <= right && count['Q'] <= k && count['W'] <= k && 
               count['E'] <= k && count['R'] <= k) {
            min_len = min(min_len, right - left + 1);
            count[s[left]]++; // Restore character back to outside frequency
            left++;
        }
    }
    
    return min_len;
}
    
};