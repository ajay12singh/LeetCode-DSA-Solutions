class Solution {
public:
    int trap(vector<int>& height) {


        int n = height.size();
        vector<int> minima(n,0);
        
        vector<int> maxima(n,0);

        int minimum =height[0];
        minima[0] = height[0];

        for(int i = 1 ; i < n; i++){

            minima[i] = minimum;
            minimum = max(minimum , height[i]);

        }
        int maxi = height[n-1];
        maxima[n-1] = height[n-1];

        for(int i = n-2 ; i >= 0; i--){

            maxima[i] = maxi;
            maxi = max(maxi,height[i]);

        }


        // calculate our result;

        int ans = 0;


        for(int i = 1 ; i < n-1 ; i++){

            int mini = min(maxima[i],minima[i]);
            
            
            if(mini - height[i] > 0) {
                ans += mini - height[i];
            }
           

        }

        return ans;
    }
};