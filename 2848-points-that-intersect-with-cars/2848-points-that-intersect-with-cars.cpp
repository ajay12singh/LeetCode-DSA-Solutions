class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {


        vector<int> diff(102,0);

        for(int i = 0 ; i < nums.size();  i++){

            int x = nums[i][0];
            int y = nums[i][1];

            diff[x] += 1;
            diff[y+1] -= 1;


         }

         for(int i = 1; i < diff.size(); i++){
            diff[i] += diff[i-1];
         }

         int count = 0;
         for(int i = 0;  i < diff.size() ; i++){

            if(diff[i]>=1) count++;

         }

         return count;
        
    }
};