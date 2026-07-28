class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int  p1 = 0;
        int p2 = 0;
        while (p2 < n ){
            if(nums[p2] != val){
                nums[p1] = nums[p2];
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        return p1;
            }
};