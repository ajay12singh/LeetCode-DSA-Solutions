class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Compare mid with its right neighbor
            if (nums[mid] < nums[mid + 1]) {
                // We are on an upward slope, peak must be to the right
                low = mid + 1;
            } else {
                // We are on a downward slope, mid could be the peak
                high = mid;
            }
        }
        // When low == high, we have found the peak
        return low;
    }
};