class Solution {
public:
    string reverseWords(string s) {


        reverse(s.begin(),s.end());

        int  i = 0, j = 0, k = 0;

        while(i< s.length()){

            while(i< s.length() && s[i] != ' '){
                s[k++] = s[i++];
            }

            if(j<k){
                reverse(s.begin()+j , s.begin()+k);
                s[k] = ' ';
                k++;
                j=k;
            }

            i++;
        }
        
        return s.substr(0,k-1);
    }
};