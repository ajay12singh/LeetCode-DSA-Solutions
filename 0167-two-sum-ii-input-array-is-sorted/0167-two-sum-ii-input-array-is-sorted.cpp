class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1 = 0 ;
        int p2 = n - 1;
        vector<int> result ={-1,-1};
        int sum = -1;
        while(p1<p2){
             sum = numbers[p1]+numbers[p2];
            if(sum  == target ) {
                result[0] = p1+1;
                result[1] = p2+1;
                break;
            }
            else if( sum > target ){
                p2--;
            }
            else {
                p1++;
            }
        }
        return result;
    }
};