class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
            int x = bookings.size();
            vector<int> diff(n+2,0);

            for(int i = 0 ; i<x ; i++){
              int y =  bookings[i][0];
               diff[y] += bookings[i][2];
               int z = bookings[i][1];
               diff[z+1] -=  bookings[i][2];
            }


            // int prefix = diff[0]

            for(int i = 1 ; i < diff.size();i++){
                diff[i] = diff[i-1]+diff[i];
            }


        vector<int> res;
        for(int i = 1; i< diff.size()-1;i++){
            res.push_back(diff[i]);
        }

        return res;
    }
};