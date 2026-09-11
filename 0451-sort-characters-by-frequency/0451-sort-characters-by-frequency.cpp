class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freqMap;
        int maxFreq = 0;
        for (char c : s) {
            freqMap[c]++;
            maxFreq = max(maxFreq, freqMap[c]);
        }

       
        vector<string> buckets(maxFreq + 1, "");
        for (auto& [ch, count] : freqMap) {
            buckets[count].push_back(ch);
        }

        
        string res = "";
        for (int i = maxFreq; i > 0; i--) {
            for (char c : buckets[i]) {
                res.append(i, c); 
            }
        }

        return res;
    }
};