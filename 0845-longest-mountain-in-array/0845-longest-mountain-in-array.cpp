class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        int count = 0;
        int ans = 0;
        for(int i = 1;i<=n-2;){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int j=i;
                count = 1;
                while(j>0 && arr[j]>arr[j-1]){
                    count++;
                    j--;
                }
            
                while(i<n-1 && arr[i]>arr[i+1]){
                    count++;
                  i++;
                }
            }
            else {
                i++;
            }
            ans = max(ans,count);
            }
             
        

    return ans;
        
    }
};