class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int iterNum = n/2;
        
        for (int i = 0; i < iterNum; ++i)
            rotateOneSquare(matrix, i);
    }
private:
    
    void rotateOneSquare(vector<vector<int>>& matrix, int startPointX)
    {
        int x = startPointX;
        int l = matrix.size() - 2*x - 1;
        
        for (int i = 0; i < l; ++i)
        {
            int tempValue      = matrix[x+i][x];
            matrix[x+i][x]     = matrix[x+l][x+i];
            matrix[x+l][x+i]   = matrix[x+l-i][x+l];
            matrix[x+l-i][x+l] = matrix[x][x+l-i];
            matrix[x][x+l-i]   = tempValue;
        }
    }
    
};
