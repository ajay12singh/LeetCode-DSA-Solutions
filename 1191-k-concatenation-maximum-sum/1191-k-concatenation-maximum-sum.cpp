class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int max_sum = INT_MIN;
        long long int current_sum = 0;
        long long int total_sum = 0;
        long long int mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            total_sum += arr[i];
            current_sum += arr[i];
            if (current_sum < 0) current_sum = 0;
            max_sum = max(max_sum, current_sum);
        }

        if (k == 1) return max_sum % mod;

        vector<int> merge;
        merge.reserve(arr.size() * 2);

        for (int i = 0; i < arr.size(); i++) {
            merge.push_back(arr[i]);
        }
        for (int i = 0; i < arr.size(); i++) {
            merge.push_back(arr[i]);
        }

       
        max_sum = INT_MIN;
        current_sum = 0;
        for (int i = 0; i < merge.size(); i++) {
            current_sum += merge[i];
            if (current_sum < 0) current_sum = 0;
            max_sum = max(max_sum, current_sum);
        }

        if (total_sum <= 0) {
            return max_sum % mod;
        } else {
         
         
           long long ans = (max_sum + (long long)(k - 2) * total_sum) % mod;
            return ans;

        }
    }
};