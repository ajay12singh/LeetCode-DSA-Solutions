class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int save = 0;
        int n = nums.size();
        int j = 0;
        while(j < nums.size()){

            if(nums[j] == key  ){
                
                    int start = max(save, j-k);
                    int end = min(n-1, j+k);

                    for(int i = start;i<=end;i++){
                        result.push_back(i);
                    }

                    save = end+1;
                       
                    
                    
                
                }
                

            
            j++;
        }
        return result;
    }
};