class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; 
        
        int count = 1; 
        int p1 = 1; 
        int p2 = 1; 
        
        while (p2 < n) {
           
            if (nums[p2] == nums[p1 - 1]) {
                count++; 
                if (count <= 2) {
                    nums[p1] = nums[p2]; 
                    p1++; 
                    p2++; 
                } else {
                    p2++; 
                } 
            } else {
                count = 1; 
                nums[p1] = nums[p2]; 
                p1++; 
                p2++; 
            } 
        } 
        return p1; 
    }
};