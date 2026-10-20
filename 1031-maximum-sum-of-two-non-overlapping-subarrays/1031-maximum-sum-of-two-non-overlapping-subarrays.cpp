class Solution {

    int max_sum(int first ,int second,vector<int>& nums){

        int p1 = 0 ;
        int p2 = first-1;
        int p3 = p2+1;
        int p4 = p3+second-1;
        int first_sum = 0;
        int second_sum = 0;

        for(int i = 0 ; i <= p2 ; i++){
            first_sum += nums[i];
        }
        for(int i = p3; i <= p4; i++){
            second_sum += nums[i];
        }

        int max_first_sum = first_sum; 
        int ans = max_first_sum + second_sum;

        for(int i = p4 + 1; i < nums.size(); i++){
           
            second_sum += nums[i] - nums[p3];
            p3++;
            

           
            first_sum += nums[p2 + 1] - nums[p1];
            p1++;
            p2++;
            max_first_sum = max(max_first_sum, first_sum);

            ans = max(ans, max_first_sum + second_sum);
        }

        return ans;
    }

public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int x = max_sum(firstLen, secondLen, nums);
        int y = max_sum(secondLen, firstLen, nums);

        return max(x, y);
    }
};