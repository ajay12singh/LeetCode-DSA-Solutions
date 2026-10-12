#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long int  ans  = 0;
        
        int  prevDiff = 0;
        
        for (int i = 0; i < n; ++i) {
            int  currDiff = target[i] - nums[i];
         
            if (currDiff < 0 && prevDiff > 0) {
                ans += abs(currDiff);
            }
         
            else if (currDiff > 0 && prevDiff < 0) {
                ans += abs(currDiff);
            }
            else if (abs(currDiff) > abs(prevDiff)) {
                ans += abs(currDiff) - abs(prevDiff);
            }
            
            prevDiff = currDiff;
        }
        
        return ans;
    }
};