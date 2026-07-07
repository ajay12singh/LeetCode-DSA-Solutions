class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();

        int p1 = 0;
        int p2 = n-1;

        int count=0;
        while(p1<=p2){

            if(people[p1]+people[p2]<=limit){
                count++;
                p1++;
                p2--;
            }
            else{
                if(people[p2]<=limit) {
                    count++;
                    p2--;
                }
                else{
                    count++;
                }
        
                
            }
        }
          return count;
        
    }
};