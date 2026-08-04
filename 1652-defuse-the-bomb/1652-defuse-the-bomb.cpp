class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        vector<int> result;
        int sum = 0;
    if(k>0){
        
        for(int i = 0; i < k ; i++){

            sum += code[i];

        }

        int j = 0;
        while(j<code.size()){

            int x = (j+k)%code.size();

            sum += code[x]-code[j];
            j++;

            result.push_back(sum);

        }
    }
    
    else if (k < 0) {
            int abs_k = abs(k);
            for (int i = 0; i < code.size(); i++) {
                int sum = 0;
                for (int j = 1; j <= abs_k; j++) {
                    int index = (i - j + code.size()) % code.size();
                    sum += code[index];
                }
                result.push_back(sum);
            }
        }
    
    else {
        for(int j = 0; j<code.size(); j++){
            result.push_back(0);
        }
    }

      

        return result;
    }
};