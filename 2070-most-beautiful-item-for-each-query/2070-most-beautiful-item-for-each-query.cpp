class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());

        for (int i = 1; i < items.size(); i++) {
        items[i][1] = max(items[i][1], items[i - 1][1]);
            }
        vector<int>result(queries.size());

        for(int i = 0 ; i < queries.size();i++){
            
            long long int  mid ;
           long long  int ans = 0;
           int low = 0;
           int high = items.size()-1;
            while(low<=high){
                mid = low+(high-low)/2;
                if(queries[i]>=items[mid][0]){
                    ans = max(ans,(long long)items[mid][1]);
                    low = mid+1;

                }
                else{
                    high = mid-1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
};