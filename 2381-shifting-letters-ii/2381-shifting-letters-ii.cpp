class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        vector<int> diff(s.length()+1,0);

        for(int i = 0; i < shifts.size();i++){

            int start = shifts[i][0];
            int end = shifts[i][1];
            

            if(shifts[i][2] == 1){
                diff[start] += 1;
                diff[end+1] -= 1;
            }

            else{
                diff[start] -= 1;
                diff[end+1] += 1;
            }
        }

        for(int i = 1; i < diff.size();i++){
            diff[i] = diff[i]+ diff[i-1];
        }
        string str = "";

   for (int i = 0; i < s.length(); i++) {
    // 1. Calculate net shift and normalize it into [0, 25]
    int netShift = ((diff[i] % 26) + 26) % 26;

    // 2. Map original character s[i] to 0-25, apply shift, and wrap around
    char shiftedChar = 'a' + (s[i] - 'a' + netShift) % 26;

    str.push_back(shiftedChar);
}

return str;
        return str;
    }
};