class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Step 1: Remove indices that are out of the current sliding window
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Step 2: Maintain monotonic order by removing smaller elements
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // Step 3: Push current element's index
            deq.push_back(i);

            // Step 4: Record maximum once window reaches size k
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};