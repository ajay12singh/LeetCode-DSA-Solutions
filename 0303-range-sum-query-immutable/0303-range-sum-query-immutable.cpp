class NumArray {
private:
    vector<int> prefix1;
    vector<int> prefix2;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix1.resize(n);
        prefix2.resize(n);

        // Your logic: prefix1[i] stores the sum of elements BEFORE index i
        prefix1[0] = 0;
        for (int i = 1; i < n; i++) {
            prefix1[i] = prefix1[i - 1] + nums[i - 1];
        }

        // Your logic: prefix2[i] stores the cumulative sum UP TO index i
        prefix2[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix2[i] = prefix2[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // Your logic: total sum up to 'right' minus the sum before 'left'
        return prefix2[right] - prefix1[left];
    }
};