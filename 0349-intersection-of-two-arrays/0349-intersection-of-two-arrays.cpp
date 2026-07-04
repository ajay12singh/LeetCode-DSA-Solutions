class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Sort the second array to enable binary search
        sort(nums2.begin(), nums2.end());
        
        // Use a set to store the result to ensure uniqueness
        unordered_set<int> resultSet;
        
        for (int target : nums1) {
            if (binarySearch(nums2, target)) {
                resultSet.insert(target);
            }
        }
        
        // Convert the set back to a vector
        return vector<int>(resultSet.begin(), resultSet.end());
    }

private:
    bool binarySearch(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};