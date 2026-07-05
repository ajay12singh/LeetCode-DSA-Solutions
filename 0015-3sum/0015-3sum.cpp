class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

         sort(nums.begin(),nums.end());

         int n = nums.size();
         
         vector<vector<int>> result;
        
        for(int i = 0 ; i < n-2; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int target = -(nums[i]);
            int p1 = i+1;
            int p2 = n-1;
            while(p1<p2){

                int sum = nums[p1]+nums[p2];

                
                if( sum ==  target){
                        result.push_back({-target,nums[p1],nums[p2]});
                

                while(p1 < p2 &&  nums[p1]==nums[p1+1]){
                    p1++;
                    
                }
                while(p1 < p2 &&  nums[p2]==nums[p2-1]){
                    p2--;
                    
                }

                p1++;
                p2--;
            }

                else if ( sum > target ) p2--;
                else p1++;
            }
        }
          return result;
    }
};