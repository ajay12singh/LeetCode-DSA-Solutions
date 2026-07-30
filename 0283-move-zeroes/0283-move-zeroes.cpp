class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int p1 = 0;
        int p2 = 0;

        for(p2 = 0; p2 < nums.size();p2++){
            if(nums[p1] == 0){
                if(nums[p2] != 0){

                    swap(nums[p1],nums[p2]);
                    p1++;
                }
            }
            else{
                p1++;
            }
        }

        // while(p2<nums.size()){

        //     if(nums[p1] == 0){
        //         if(nums[p2]==0) p2++;
        //         else{
        //             swap(nums[p1],nums[p2]);
        //             p1++;
        //             p2++;

        //         }
        //     }
        //     else{
        //         p1++;
        //         p2++;
        //     }
        // }
        
    }
};