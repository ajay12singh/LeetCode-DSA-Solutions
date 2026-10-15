class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int max_val = 0;
        for (int i = 0; i < segments.size(); i++) {
            if (segments[i][1] > max_val) {
                max_val = segments[i][1];
            }
        }
        vector<long long> diff(max_val+2,0);
        vector<bool> is_boundary(max_val + 2, false);

        for(int i = 0; i < segments.size();i++){
            int start = segments[i][0];
            int end = segments[i][1];

            diff[start] += segments[i][2];
            diff[end] -= segments[i][2];

            is_boundary[start] = true;
            is_boundary[end] = true;


    }


    for(int i = 1; i < diff.size();i++){
        diff[i] +=diff[i-1];
    }

    int first = 0;
    int j = 0;

    while(j<diff.size() && diff[j] == 0){
         
         j++;
    }

    first = j;

    long long int change = diff[first];

    vector<vector<long long>> res;


    for (int i = first; i <= max_val; ) {

    if (diff[i] == 0) {
        i++;
        first = i;
        if (i <= max_val) change = diff[i];
        continue;
    }

    while (i <= max_val && diff[i] == change && !is_boundary[i]) {
        i++;
    }
    if (i <= max_val && diff[i] == change && is_boundary[i] && i == first) {
        i++;
        while (i <= max_val && diff[i] == change && !is_boundary[i]) {
            i++;
        }
    }

    int last = i;
    res.push_back({(long long)first, (long long)last, change});

    first = last;
    if (first <= max_val) change = diff[first];
}



        return res;



    }

};