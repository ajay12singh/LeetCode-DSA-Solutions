class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> diff(nums.size(), 0);
        int mod = 1e9 + 7;

        for (int i = 0; i < requests.size(); i++) {
            int start = requests[i][0];
            int end = requests[i][1];

            diff[start] += 1;
            if (end + 1 < diff.size()) {
                diff[end + 1] -= 1;
            }
        }

        
        for (int i = 1; i < diff.size(); i++) {
            diff[i] = diff[i - 1] + diff[i];
        }

        sort(diff.begin(), diff.end());
        sort(nums.begin(), nums.end());

        long long int ans = 0; 

        for (int i = diff.size() - 1; i >= 0; i--) {
           
            ans = (ans + ((long long)diff[i] * nums[i]) % mod) % mod;
        }

        return ans;
    }
};