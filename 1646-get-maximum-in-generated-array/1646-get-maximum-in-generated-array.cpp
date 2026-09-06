class Solution {
public:
    int getMaximumGenerated(int n) {

         int ans = 0;
         vector<int> arr( n+1,0);
         if(n==0) return 0;
         if(n==1) return 1;
         arr[0] = 0;
         arr[1]=1;
        //  if(n==2) return 1;

         for(int i = 1; i<=n/2;i++){

                if(i == (float)n/2){
                arr[2*i] =arr[i];
                // arr[2*i+1] = arr[i]+arr[i+1];
                ans = max(ans,arr[2*i]);
                }
                else{
                arr[2*i] =arr[i];
                arr[2*i+1] = arr[i]+arr[i+1];
                ans = max(ans,arr[2*i+1]);


                }
                // else{
                //     if(i<n/2){
                //          arr[2*i] =arr[i];
                //          arr[2*i+1] = arr[i]+arr[i+1];

                //     }
                //     else if(i == n/2){
                //         arr[2*i] =arr[i];

                //     }

                    // ans = max(ans,arr[2*i]);
                }

         

         return ans;
        
    }
};