class Solution {
    bool allZero(vector<int>& counter) {
        for(int &i : counter) {
            if(i != 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {

        int n = s2.length();
       
        
        vector<int> counter(26, 0);
        
        for(int i = 0; i < s1.length(); i++) {
            char ch = s1[i];
            counter[ch - 'a']++;
        }
        
        int i = 0, j = 0;

        int k = s1.length();
        
        while(j < n) {
            counter[s2[j] - 'a']--;
            
            if(j - i + 1 == k) {
                if(allZero(counter)) {
                    return true;
                }
                
                counter[s2[i] - 'a']++;
                i++;
            }
            
            j++;
        }
        
        return false ;
        
    }
};