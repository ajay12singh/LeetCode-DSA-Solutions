class Solution {


    // recursion +mem 

    int t[1001][1001];

    bool solve(int i , int j , string &s ){


        if(i>=j){
            return 1;
        }
        
        
    if (t[i][j] != -1) {
        return t[i][j];
    }
        if(s[i] == s[j]){
        return t[i][j] = solve(i+1,j-1,s);
        }

        return t[i][j] = 0;


    }
public:
    string longestPalindrome(string s) {
        

        int max_length = -1;
        int sp = 0;

        //mem initialization
        memset(t,-1,sizeof(t));



        for(int i = 0 ; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){



                if(max_length< j-i+1  && solve(i,j,s)==true ){
                    max_length = j-i+1;
                    sp = i;

                }


            }
        }

        return s.substr(sp,max_length);
    }
};