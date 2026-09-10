class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> c;

        for(int i=0;i<s.size();i++){
            c[s[i]]++;
        }
        int ans=0;
        for(auto a:c){
            if((a.second%2)==1){
                ans++;
                a.second--;
                break;
            }
        }
        for(auto a:c){
            ans=ans+ (2*(a.second/2));
        }
        return ans;
        
    }
};