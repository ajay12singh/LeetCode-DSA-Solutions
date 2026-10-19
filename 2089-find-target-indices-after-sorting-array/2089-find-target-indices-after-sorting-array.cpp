class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {  
        // sort(nums.begin() , nums.end());
        int count = 0;
        int small_num = 0;

        for(int i = 0 ;i < nums.size() ; i++){



            if(target>nums[i] ) small_num++;
            if(target == nums[i]) count++;



        }


        vector<int> res;

        while(count > 0 ){
            res.push_back(small_num);
            small_num++;
            count--;
        }
    return res;

        

    }
};