class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        unordered_set<int> resultSet;
        
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];
            int low = 0;
            int high = nums2.size() - 1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums2[mid] == target) {
                    resultSet.insert(target);
                    break;
                } else if (nums2[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};