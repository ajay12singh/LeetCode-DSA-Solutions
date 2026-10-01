class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        int ans = INT_MAX;

        for (int i = 0; i < timePoints.size(); i++) {
            
            string hr = timePoints[i].substr(0, 2);
            string m = timePoints[i].substr(3, 2);

            int hour = stoi(hr);
            int minutes = stoi(m); 

            int time_in_min = hour * 60 + minutes;
            time.push_back(time_in_min);
        }

        sort(time.begin(), time.end());

        for (int i = 0; i < time.size() - 1; i++) {
            ans = min(ans, time[i + 1] - time[i]);
        }

        return min(ans, 1440 - time.back() + time.front());
    }
};