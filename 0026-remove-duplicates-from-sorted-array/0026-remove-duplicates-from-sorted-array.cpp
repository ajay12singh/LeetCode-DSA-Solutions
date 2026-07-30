class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int p1 = 0;
        int p2 = 0;
        for(p2 = 0; p2<nums.size();p2++){
            if(nums[p1] != nums[p2]){
                p1++;
                nums[p1] = nums[p2];
                
            }
        }

        // while(p2<nums.size()){
        //     if(nums[p1] == nums[p2]){
        //         p2++;
        //     }
        //     else{
        //         p1++;
        //         nums[p1]=nums[p2];
        //         p2++;
        //     }


        // }
        return p1+1;
    }
};