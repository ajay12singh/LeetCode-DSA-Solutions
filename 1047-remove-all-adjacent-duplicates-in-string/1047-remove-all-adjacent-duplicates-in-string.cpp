class Solution {
public:
    string removeDuplicates(string s) {
        // no need stack due to string in cpp we can use push,pop concepty okk brother ; 
        string res ="";
        
        for(char x :s){

            if(!res.empty() && res.back() == x){
                res.pop_back();
            }

            else {
                res.push_back(x);
            }

        }

        return res;
        
    }
};