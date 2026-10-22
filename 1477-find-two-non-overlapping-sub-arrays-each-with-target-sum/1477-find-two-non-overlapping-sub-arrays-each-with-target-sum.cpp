class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int current_sum = 0;

        vector<int> min_len_till_idx(n, INT_MAX);
        int best_min_len = INT_MAX;
        int result = INT_MAX;

        while (j < n) {
            current_sum += arr[j];

            while (i <= j && current_sum > target) {
                current_sum -= arr[i++];
            }

            if (current_sum == target) {
                int len = j - i + 1;

                if (i > 0 && min_len_till_idx[i - 1] != INT_MAX) {
                    result = min(result, len + min_len_till_idx[i - 1]);
                }

                best_min_len = min(best_min_len, len);
            }

            min_len_till_idx[j] = best_min_len;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};