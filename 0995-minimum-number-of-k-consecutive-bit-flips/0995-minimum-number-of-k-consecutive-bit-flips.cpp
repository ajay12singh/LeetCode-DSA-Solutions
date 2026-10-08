class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCountFromPastForCurri = 0;
        
        // Deque of size up to k to store flip status (1 if flipped, 0 if not)
        deque<int> flipQ;
        
        for (int i = 0; i < n; i++) {
            // Remove the flip effect of the element going out of the k-window
            if (i >= k) {
                flipCountFromPastForCurri -= flipQ.front();
                flipQ.pop_front();
            }
            
            // Check if the current bit needs to be flipped
            if (flipCountFromPastForCurri % 2 == nums[i]) {
                // If flipping requires extending beyond array boundary, it's impossible
                if (i + k > n) {
                    return -1;
                }
                
                flips++;
                flipCountFromPastForCurri++;
                flipQ.push_back(1); // Flipped at index i
            } else {
                flipQ.push_back(0); // Not flipped at index i
            }
        }
        
        return flips;
    }
};