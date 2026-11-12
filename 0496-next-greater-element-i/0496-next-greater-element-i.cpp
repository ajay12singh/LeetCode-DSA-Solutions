class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
    unordered_map<int, int> mp; 
    for (int i = 0; i < nums1.size(); i++) {
        mp[nums1[i]] = i;
    }

    vector<int> ans(nums1.size(), -1);
    stack<int> st; 

    for (int curr : nums2) {
        
        while (!st.empty() && curr > st.top()) {
            int val = st.top();
            st.pop();
            ans[mp[val]] = curr; 
        }

        
        if (mp.count(curr)) {
            st.push(curr);
        }
    }

    return ans;

    }
};