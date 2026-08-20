class NumArray {
private:
    // Store the prefix sums as a member variable so all functions can access it
    vector<int> prefix;

public:
    // Constructor: Precomputes the prefix sum array once
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    // Member function: Answers queries using the stored prefix array
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};