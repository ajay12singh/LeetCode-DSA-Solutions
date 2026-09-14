class Solution {
public:
    bool isPalindrome(string s) {

        int f=0;
        int l=s.size()-1;

        while(f<l){
            while(f<l && !isalnum(s[f])){
                f++;
            }
            while(f<l && !isalnum(s[l])){
                l--;
            }
            if(tolower(s[f]) != tolower(s[l])){
                return false;
            }
            else{
                f++;
                l--;
            }
        }
        return true;
        
    }
};