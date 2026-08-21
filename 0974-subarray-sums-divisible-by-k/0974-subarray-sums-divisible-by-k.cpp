class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int result = 0;
        int cumSum = 0;
        
        mp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            cumSum += nums[i];
            
            int rem = cumSum % k;
            
            if (rem < 0) {
                rem += k;
            }
            
            if (mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            
            mp[rem]++;
        }
        
        return result;
    }
};