class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        // Calculate total sum % p
        int sum = 0;
        for (int num : nums) {
            sum = (sum + num) % p;
        }
        
        int target = sum % p;
       
        if (target == 0) {
            return 0;
        }
        
        
        unordered_map<int, int> mp;
        
        mp[0] = -1;
        
        int current = 0;
        int result = n;
        
        for (int j = 0; j < n; j++) {
            current = (current + nums[j]) % p;
           
            int remain = (current - target + p) % p;
            
            if (mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }
            
            
            mp[current] = j;
        }
        
        return result == n ? -1 : result;
    }
};