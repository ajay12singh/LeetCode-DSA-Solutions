class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int current=0;
        int prev = 0;
        int ans = 1;
        int length = 1;

        for(int i = 1 ; i < arr.size(); i++){

            if(arr[i]<arr[i-1]) current = 0;
            else if (arr[i]>arr[i-1]) current = 1;
            else {
                current = -1;
            }
            // reset need here because both are same 
            if(current == -1) {
                length = 1;
                prev = -1;
            }
           else if(current == prev ){
                length = 2;
                prev = current;
                ans = max(ans,length);

            }

            else{
                length++;
                ans = max(ans,length);
                prev = current;
            }
            
        }
        
        return ans;
    }
};