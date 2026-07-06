class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        int mod = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int p1 = 0;
        int p2 = nums.size()-1;
        int ans = 0;

        vector<int> pow2(nums.size());
        pow2[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        while(p1 <= p2){
            int sum=nums[p1]+nums[p2];
            if(sum <= target){
                ans = (ans + pow2[p2-p1])%mod;
                p1++;
            }
            else  p2--;
            
        }

    return ans;
        
    }
};