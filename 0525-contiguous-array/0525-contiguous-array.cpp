class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> map;

        map[0] = -1;

        // for(int i = 0; i < nums.size(); i++){

        //     if(nums[i]==0) nums[i] = -1;
        // }
        int ans = 0;
        int sum = 0;
        for(int i = 0;  i < nums.size(); i++){

            sum += (nums[i] == 1)? 1:-1;

            if(map.find(sum) != map.end()){
                ans = max(ans,i - map[sum]);
            }
            // why else due to we don't want to push sum = 0 again in new index because we want to get max subarray !
            else map[sum] = i;

        }


        return ans;
        
        
    }
};