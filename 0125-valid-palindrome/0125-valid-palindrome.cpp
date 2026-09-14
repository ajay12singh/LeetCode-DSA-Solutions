class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;


        int p1 = 0;
        int p2 = s.length()-1;

        while(p1<p2){


                if(isalnum(s[p1])){
                    char x =tolower(s[p1]);
                    if(isalnum(s[p2])){
                        char y = tolower(s[p2]);
                    if(x!=y){
                       return false;
                    }
                    else{
                        p1++;
                        p2--;
                    }
                    }
                    
                    else{
                        p2--;
                    }

                }
                
                
                else{
                    p1++;
                }

        }

        return true;

    }
};