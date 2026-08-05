class Solution {

     int sliding_window(vector<int> &nums, int k){
        unordered_map<int,int> map;

        int count = 0;

        int i = 0;
        int j = 0;

        while(j<nums.size()){
            map[nums[j]]++;
            
        

        while(map.size()>k){

            map[nums[i]]--;
            if(map[nums[i]]==0) map.erase(nums[i]);
            i++;
        }

        count += j-i +1;
        j++;
       
        }
         return count;
        }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       

        return sliding_window(nums,k) - sliding_window(nums,k-1);


        
    }
};