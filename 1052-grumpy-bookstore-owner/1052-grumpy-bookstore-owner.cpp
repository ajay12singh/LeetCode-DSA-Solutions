class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {


        int unsatisfied = 0;
        for(int i = 0 ; i < minutes; i++){
           if(grumpy[i] == 1) unsatisfied +=customers[i];
        }
        
        int i = 0;
        int j = minutes;
        int maxi = unsatisfied;
        while(j<customers.size()){
            if(grumpy[i]==1) unsatisfied -= customers[i];
            if(grumpy[j] == 1) unsatisfied +=customers[j];
            i++;
            j++;
            maxi = max(maxi,unsatisfied);

        }
        int sum = 0;

        for(int i = 0; i< customers.size();i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }

        }

        return sum+maxi;
        
    }
};