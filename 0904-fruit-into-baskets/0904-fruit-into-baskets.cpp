class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int i = 0, j = 0;
        int ans = 0;
        int k = 2;

        while (j < fruits.size()) {
            freq[fruits[j]]++;

            int size = freq.size();
            int allow = k - size; 
           
            while (allow < 0) {
                freq[fruits[i]]--;
                
               
                if (freq[fruits[i]] == 0) {
                    freq.erase(fruits[i]);
                }
                
                i++;
                
                
                allow = k - freq.size(); 
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};