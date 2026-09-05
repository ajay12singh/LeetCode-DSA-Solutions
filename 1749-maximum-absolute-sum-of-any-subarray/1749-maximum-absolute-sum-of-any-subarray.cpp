class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        // int min_sum = INT_MAX; 
        // int max_sum = INT_MIN;
        // int current_sum = 0;
        

        // for(int i = 0 ; i< nums.size();i++){

        //     current_sum += nums[i];

        //     if(current_sum<0) current_sum = 0;
        //     max_sum = max(max_sum,current_sum);
        // }

        //   current_sum = 0;


        //  for(int i = 0 ; i< nums.size();i++){

        //     current_sum += nums[i];

        //     if(current_sum>0) current_sum = 0;
        //     min_sum = min(min_sum,current_sum);
        // }


        // return max(abs(min_sum),abs(max_sum));



       
        int ps = 0;
        int mi = 0;
        int mx = 0;
        for(int i: nums){
            ps+=i;
            if(mi > ps) mi = ps;
            if(mx < ps) mx = ps;
        }
        if(mx == mi) return abs(mi);
        return abs(mi-mx);
    


        
    }
};