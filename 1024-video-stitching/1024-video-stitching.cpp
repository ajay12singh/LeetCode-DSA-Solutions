class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int ans = 0;
        int prev_end = 0;
        int max_end = 0;
        int i = 0;
        int n = clips.size();

        while (prev_end < time) {
            
            while (i < n && clips[i][0] <= prev_end) {
                max_end = max(max_end, clips[i][1]);
                i++;
            }

            
            if (prev_end == max_end) return -1;

          
            prev_end = max_end;
            ans++;
        }

        return ans;
    }
};