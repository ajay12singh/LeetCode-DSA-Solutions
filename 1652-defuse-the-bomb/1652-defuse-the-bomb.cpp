class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int i = -1,j=-1;
        vector<int> result(code.size(),0);

        if(k == 0) return result;
        if(k>0){
            i = 1;
            j = k; 
        }

        else {
            i = code.size() - abs(k);
            j = code.size() - 1;
        }
        int window = 0;
        for(int pointer = i; pointer <=j ; pointer++){
            window += code[pointer];
        }

        for(int k= 0 ; k < code.size(); k++){

            result[k] = window;

            window -= code[i % code.size()];
            i++;
            window += code [(j+1)% code.size()];
            j++;
        }

        return result;
    }
};