class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

         vector<int> ans(nums.size(),-1 );

         stack<int> st;


         for(int i = 0 ; i < 2 * nums.size() ; i++ ){

            int k = i%nums.size();

            while(!st.empty() && nums[k] > nums[st.top()] ){
                int x = st.top();
                st.pop();
                ans[x] = nums[k];
            }
        if(i < nums.size())
             st.push(k);

         }


         
         return ans;
        
    }
};