class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i = 0;
        int no_power = arr[i];
        int power = 0;
        int res = arr[i];

        for(i=1; i<arr.size(); i++){
            int v1 = arr[i];
            int v2 = no_power + arr[i];
            int v3 = power + arr[i];
            int v4 = no_power;
            

            no_power = max(v1,v2);
            power = max(v3,v4);
            res = max(res,max(no_power,power));





        }
        return res;
    }
};