class Solution {
public:
    int minOperations(vector<int>& nums) {
       
   
        int n = nums.size();
        int flips = 0;
        int flipCountFromPastForCurri = 0;
        
        // Auxiliary array to track whether an index was flipped
        vector<bool> isFlipped(n, false);
        
        for (int i = 0; i < n; i++) {
            // Remove the effect of the flip that goes out of the current k-window
            if (i >= 3) {
                if (isFlipped[i - 3]) {
                    flipCountFromPastForCurri--;
                }
            }
            
            // Check if the current bit needs to be flipped
            if (flipCountFromPastForCurri % 2 == nums[i]) {
                // If we need to flip but cannot due to array bounds
                if (i + 3 > n) {
                    return -1;
                }
                
                flips++;
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
            }
        }
        
        
        return flips;
 
    }
};