class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCountFromPast = 0;
        
        // diff[i] tracks the boundary of flip effects.
        // Size n + 1 prevents out-of-bounds when marking the end of a window at i + k.
        vector<int> diff(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            // Remove the effect of a flip window that has expired
            flipCountFromPast ^= diff[i]; // If using XOR or standard addition/subtraction
            
            // Alternatively, with standard sum:
            // flipCountFromPast -= diff[i];
            
            // Check if current bit needs a flip
            // (nums[i] ^ flipCountFromPast % 2) gives the effective current bit value
            int currentBit = nums[i] ^ (flipCountFromPast & 1);
            
            if (currentBit == 0) {
                // If flipping extends beyond the array boundary, it's impossible
                if (i + k > n) {
                    return -1;
                }
                
                flips++;
                flipCountFromPast++;
                
                // Mark the start of the flip effect at i
                // and its expiration right after the window ends (at i + k)
                diff[i + k] ^= 1; // or diff[i + k] += 1 depending on implementation
            }
        }
        
        return flips;
    }
};