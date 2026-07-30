class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int p1 = 2; 
        for (int p2 = 2; p2 < nums.size(); p2++) {
            
            if (nums[p2] != nums[p1 - 2]) {
               
                nums[p1] = nums[p2];
                 p1++;
                
            }
        }
        return p1;
    }
};