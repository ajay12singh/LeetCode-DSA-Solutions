class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int p1 = 0;
        int p2 = tokens.size()-1;
        int score=0;
        while(p1<=p2){

            if(tokens[p1]<=power){
                power -= tokens[p1];
                score++;
                p1++;
            }
            else{
            if(score>=1 && p1 != p2){
                    power +=tokens[p2];
                    p2--;
                    score-=1;
                }
                else{
                    p2--;
                }
            }
        }
         
         return score;

    }
};