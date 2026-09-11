class Solution {
public:
    string frequencySort(string s) {
    
        vector<pair<int, char>> freq(128);
        for (int i = 0; i < 128; i++) {
            freq[i] = {0, (char)i};
        }
        
        for (char c : s) {
            freq[c].first++;
        }

       
        sort(freq.rbegin(), freq.rend());

        string res = "";
        res.reserve(s.length()); 
        for (auto& [count, ch] : freq) {
            if (count == 0) break; 
            res.append(count, ch);
        }

        return res;
    }
};