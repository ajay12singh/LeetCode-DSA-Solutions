using namespace std;

class NumMatrix {
private:
    vector<vector<int>> pref;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        pref = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                pref[r + 1][c + 1] = pref[r + 1][c] + matrix[r][c];
            }
        }
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                pref[r + 1][c + 1] += pref[r][c + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] 
             - pref[row1][col2 + 1] 
             - pref[row2 + 1][col1] 
             + pref[row1][col1];
    }
};