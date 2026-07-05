class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        
        long long int sum1 = -1,sum2 = -1;
        for(int p1 = 0; p1 < n - 3 ; p1++){
            if(p1>0 && nums[p1]==nums[p1-1] ) continue;
            for ( int p2 = p1+1; p2 < n-2; p2++ ){
                if (p2 > p1 + 1 && nums[p2] == nums[p2 - 1]) continue;
                int p3  = p2 + 1 ; 
                int p4  = n -1;

                while(p3<p4){

                    sum1  = nums[p1] + nums[p2] ;
                    sum2=  nums[p3] + nums[p4];

                    if (sum1+sum2 == target) {
                        result.push_back({nums[p1],nums[p2],nums[p3],nums[p4]});

                        while(p3<p4 && nums[p3]==nums[p3+1]) p3++;
                        while(p3<p4 && nums[p4]==nums[p4-1]) p4--;
                        p3++;
                        p4--;

                    }
                    else if(target > sum1+sum2) p3++;
                    else p4--;
                }
            }
        }
        return result;
    }
};