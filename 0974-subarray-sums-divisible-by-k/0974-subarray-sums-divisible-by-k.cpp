class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1; // Base case: remainder 0 starts with count 1
        
        int cumulative_sum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            cumulative_sum += nums[i];

            
            int rem = ((cumulative_sum % k) + k) % k;

            
            if (map.find(rem) != map.end()) {
                result += map[rem];
            }

           
            map[rem]++;
        }

        return result;
    }
};