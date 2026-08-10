
        class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int max_dist = 0;
        int i = -1; 
        for (int j = 0; j < n; j++) {
            if (seats[j] == 1) {
             
                if (i == -1) {
                    max_dist = max(max_dist, j);
                } 
                
                else {
                    max_dist = max(max_dist, (j - i) / 2);
                }
                
               
                i = j; 
            }
        }

       
        if (seats[n - 1] == 0) {
            max_dist = max(max_dist, (n - 1) - i);
        }

        return max_dist;
    }
};
         
        
  