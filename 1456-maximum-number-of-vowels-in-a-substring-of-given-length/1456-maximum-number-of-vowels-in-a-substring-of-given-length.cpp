class Solution {
    bool isVowel(char ch){
        if(ch == 'a'|| ch == 'e'|| ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
    }
public:
    int maxVowels(string s, int k) {
         int max_count=0;
        int i = 0;
        int count = 0;
        int j = k;
        for(int i = 0; i<k ; i++){
            
            char ch = s[i];
           if( isVowel(ch) ){
                count++;
            }
            
        }
        max_count = count;
       
    
         
         while(j<s.length()){


            if(isVowel(s[i])){
                count--;
            }
            
            if(isVowel(s[j])){
                count++;
            }
            max_count  = max(max_count,count);

        i++;

        j++;

         }
    return max_count;
    }
};