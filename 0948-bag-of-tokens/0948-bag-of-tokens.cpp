class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int p1 = 0;
        int p2 = tokens.size()-1;
        int score=0;
        int maxscore=0;//save the score if score == 1 and remaining one element at last so not decrement on score 
        while(p1<=p2){

            if(tokens[p1]<=power){
                power -= tokens[p1];
                score++;
                p1++;
                maxscore=max(score,maxscore);
            }
            else{
            if(score>=1 ){
                    power +=tokens[p2];
                    p2--;
                    score-=1;
                }
                else{
                    break;
                }
            }
        }
         
         return maxscore;

    }
};