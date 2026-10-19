class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int one_delete = arr[0];
        int no_delete = arr[0];
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++){

            one_delete = max(no_delete,one_delete+arr[i]);
            no_delete = max(arr[i],no_delete+arr[i]);


          ans =    max({ans,one_delete,no_delete});
        
        }


        return ans;
        

         
        
    }
};