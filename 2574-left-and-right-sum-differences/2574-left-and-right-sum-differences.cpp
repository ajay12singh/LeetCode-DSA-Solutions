class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        // vector<int> left(nums.size(),0);
        // vector<int> right(nums.size(),0);

        // left[0] = 0;
        vector<int> result(nums.size(),0);

        for(int i=1; i<nums.size();i++){
            result[i] = result[i-1]+nums[i-1];
        }

        // right[nums.size()-1] = 0;

        int save = 0;
        // result[nums.size()-1] = abs(result[nums.size()-1] -save);

        for(int i = nums.size()-1;i>=0;i--){
            result[i] = abs(result[i]-save);
            save +=nums[i];
        }

        

        // for(int i = 0; i< nums.size();i++){
        //     result.push_back(abs(left[i]-right[i]));
        // }
        

        return result;
    }
};