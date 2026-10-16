class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        map<int, int> diff;

        for (int i = 0 ; i < flowers.size() ; i++) {
            int start = flowers[i][0];
            int end = flowers[i][1];

            diff[start] += 1;
            diff[end + 1] -= 1;
        }

        int running_sum = 0;
        for (auto& [time, count] : diff) {
            running_sum += count;
            count = running_sum;
        }

        vector<int> res;

        for (int i = 0 ; i < people.size() ; i++) {
            auto it = diff.upper_bound(people[i]);
            if (it == diff.begin()) {
                res.push_back(0);
            } else {
                res.push_back(prev(it)->second);
            }
        }

        return res;
    }
};