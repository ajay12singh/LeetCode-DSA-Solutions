#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        // dp[i][0] -> Max sum ending at i with 0 deletions
        // dp[i][1] -> Max sum ending at i with 1 deletion
        vector<vector<int>> dp(n, vector<int>(2));
        
        // Base cases
        dp[0][0] = arr[0];
        dp[0][1] = -1e9; // Deleting the only element leaves an empty array (not allowed)
        
        int overallMax = arr[0];
        
        for (int i = 1; i < n; i++) {
            // Choice 0: Start fresh or extend without deletion
            dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);
            
            // Choice 1: Delete current element OR keep current element after an earlier deletion
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
            
            overallMax = max({overallMax, dp[i][0], dp[i][1]});
        }
        
        return overallMax;
    }
};