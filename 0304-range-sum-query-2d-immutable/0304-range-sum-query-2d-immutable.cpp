#include <vector>

class NumMatrix {
private:
    std::vector<std::vector<int>> rowPrefix;

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
       
        rowPrefix = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                
                rowPrefix[r + 1][c + 1] = rowPrefix[r + 1][c] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = 0;
        
        
        for (int r = row1; r <= row2; ++r) {
            
            totalSum += rowPrefix[r + 1][col2 + 1] - rowPrefix[r + 1][col1];
        }
        
        return totalSum;
    }
};