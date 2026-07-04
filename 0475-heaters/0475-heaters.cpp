class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        int current_ans  = 0;

        for ( int i = 0 ; i < houses.size();i++){

            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            

            int distRight = (it == heaters.end()) ? INT_MAX : abs(*it - houses[i]);
            int distLeft = (it == heaters.begin()) ? INT_MAX : abs(*prev(it)-houses[i] );
           
            current_ans = min(distLeft, distRight);
            ans = max(ans,current_ans);
        }
        return ans;
        
    }
};