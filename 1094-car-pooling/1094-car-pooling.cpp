class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Size array to 1001 to handle max location constraint safely
        vector<int> diff(1001, 0);

        for(int i = 0 ; i < trips.size(); i++){
            // Board passengers at trips[i][1] (removed +1 offset)
            diff[trips[i][1]] += trips[i][0]; 

            // Drop passengers off at trips[i][2] (removed +1 offset and double negative)
            diff[trips[i][2]] -= trips[i][0]; 
        }

        // Calculate running passenger count (prefix sum)
        for(int i = 1 ; i < diff.size(); i++){
            diff[i] = diff[i-1] + diff[i];
        }

        // Check if passenger count exceeds capacity at any location
        for(int i = 0 ; i < diff.size(); i++){
            if(diff[i] > capacity) return false;
        }

        return true;
    }
};