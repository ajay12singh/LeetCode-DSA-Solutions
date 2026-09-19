class Solution {
public:
    int compress(vector<char>& chars) {

        int index = 0;
        int i = 0;
        
        

        while(i < chars.size()){
           int  curr_char = chars[i];

            int count = 0;

            while(i<chars.size() && curr_char == chars[i]){

                count++;
                i++;

            }

                chars[index] = curr_char;
                index++;

            if(count>1){

                string count_str = to_string(count);

                for(int j = 0 ; j< count_str.length(); j++){
                    chars[index] = count_str[j];
                    index++;
                }
            }

            
            
        }
        
        return index;
        
    }
};