class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int p1 = 0;
        int p2 = nums.size()-1;
        vector<int> result(nums.size());
        int k = nums.size()-1;

        while(p1<=p2){

            if(abs(nums[p1])<abs(nums[p2])){
                result[k] = nums[p2]*nums[p2];
                p2--;
            }
            else {
                result[k] = nums[p1]*nums[p1];
                p1++;
            }
            k--;
        }

      return result;  
    }
};