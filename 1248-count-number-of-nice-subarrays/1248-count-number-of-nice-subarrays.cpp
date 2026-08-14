class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int count_window = 0;
        int count_even = 0;
        int ans = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                count_window++;
                count_even = 0; 
            }

            
            while (count_window > k) {
                if (nums[i] % 2 != 0) {
                    count_window--;
                }
                i++;
            }

           
            if (count_window == k) {
                while (i < j && nums[i] % 2 == 0) {
                    count_even++;
                    i++;
                }
                ans += count_even + 1;
            }

            j++;
        }

        return ans;
    }
};