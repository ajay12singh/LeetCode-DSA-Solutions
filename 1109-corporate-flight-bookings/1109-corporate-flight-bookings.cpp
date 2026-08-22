class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for (int i= 0 ; i < bookings.size();i++) {
            // Index 0: first flight, Index 1: last flight, Index 2: seats
            for (int j = bookings[i][0]; j <= bookings[i][1]; j++) {
                res[j-1] += bookings[i][2];
            }
        }

        return res;
    }
};