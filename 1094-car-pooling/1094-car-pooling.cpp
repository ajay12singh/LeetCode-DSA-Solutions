class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {


     int n = trips.size();
    
     vector<int> diff(1001,0);

     for(int i = 0; i < n ; i++){
        int ex1 = trips[i][1];
        diff[ex1] += trips[i][0];
        int ex2 = trips[i][2];
        diff[ex2]  -= trips[i][0];
     }
    
     for(int i = 1; i <1001; i++){
        diff[i] = diff[i-1] + diff[i];
        
     }

    for(int i = 0 ; i<1001; i++){
        if(diff[i]>capacity) return false;
    }
        
        return true;
    }
};