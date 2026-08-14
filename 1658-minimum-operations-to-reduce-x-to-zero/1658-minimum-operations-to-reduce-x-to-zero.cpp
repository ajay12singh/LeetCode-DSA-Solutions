class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total_sum=0;

        for(int i = 0; i< nums.size();i++){

            total_sum += nums[i];

        }

        if(total_sum<x) return -1;

        int i = 0; 
        int j  = 0;
        int current_sum = 0;
        int target = total_sum - x;
        int ans = -1;
        while(j < nums.size()){

            current_sum += nums[j];

          



            while(target < current_sum ) {
                current_sum -= nums[i];
                i++;
            }
              if(target == current_sum )  ans = max(ans, j-i+1);

            j++;
        }
        
      if(ans == -1  ) return ans;
      else return nums.size() - ans;
    }
};