class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int p1 = 0;
        int p2 = 1;
        while(p2<nums.size()){
            if(nums[p1] == nums[p2]){
                nums[p1]=2*nums[p1];
                nums[p2] = 0;
                p1++;
                p2++;
            }
            else{
                p1++;
                p2++;

            }
        }
     
    p1 = 0,p2 = 1;
    while(p2<nums.size()){

        if(nums[p1]==0){
            if(nums[p2]==0){
                p2++;
            }
            else{
                swap(nums[p1],nums[p2]);
                p1++;
                p2++;
            }

        }
        else{
            p1++;
            p2++;
        }
    }
    return nums;
    }
};