class Solution {
public:
    int compareVersion(string version1, string version2) {

        int p1 = 0; 
        int p2 = 0;

        int n = version1.size();
        int m = version2.size();

        int x = 0;
        int y = 0;

        while(p1<n || p2<m){

        
            string v1 = "0";
            string v2 = "0";
            //extract number from point 
            while(p1<n && version1[p1]  != '.'){
                
                v1.push_back(version1[p1]);
                p1++;
            }
            p1++;
            if(v1 != ""){
            x = stoi(v1);
            }

            while(p2<m && version2[p2] != '.'){

                    v2.push_back(version2[p2]);
                    p2++;

            }
            p2++;
            if(v2 != ""){
             y = stoi(v2);
            }

             if(x > y ) return 1;
             else if(x<y) return -1; 

            



        }
        

        // now after the end check further 
        
        return 0;
        
    }
};