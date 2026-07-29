class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        int p2 = nums.size()-1;
        int p1 = nums.size() - 2;

        while(p1>=0){

            sum+=min(nums[p1],nums[p2]);

            p1 = p1-2;
            p2 = p2 -2;
        }
        return sum;
    }
};