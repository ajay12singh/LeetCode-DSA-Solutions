class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> left_max(height.size(),0);

        vector<int> right_max(height.size(),0);

        int maxi = 0;

        for(int i = 0; i < height.size();i++){

            left_max[i] = maxi;
 
            maxi = max(height[i],maxi);
            

        }
        maxi= 0;
         for(int i = height.size() - 1; i>=0 ;i--){

            right_max[i] = maxi;
 
            maxi = max(height[i],maxi);
            

        }

int ans = 0;
        for(int i = 0; i< height.size();i++){

            if(height[i]<min(left_max[i],right_max[i])){
                ans += min(left_max[i],right_max[i])-height[i];
            }
        }

return ans;

        
    }
};