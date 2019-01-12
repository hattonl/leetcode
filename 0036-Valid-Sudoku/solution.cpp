class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        // vector <bool> numbers(9, false);
        bool numbers[9] = {false};
        for (int row = 0; row < 9; ++row) // check each rows
        {
            // check the row[i]
            fill(numbers, numbers + 9, false);
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col] != '.')
                {
                    int index = board[row][col] - '0' - 1;
                    if (numbers[index] == true) return false;
                    else numbers[index] == true;
                }
            }
        }

        for (int col = 0; col < 9; ++col) // check each columns
        {
            fill(numbers, numbers + 9, false);
            for (int row = 0; row < 9; ++row)
            {
                if (board[row][col] != '.')
                {
                    int index = board[row][col] - '0' - 1;
                    if (numbers[index] == true) return false;
                    else numbers[index] == true;
                }
            }
        }

        for (int row = 0; row < 9; row += 3)
        {
            for (int col = 0; col < 9; col += 3)
            {
                // check
                int row_offset = 0;
                int col_offset = 0;
                fill(numbers, numbers+9, false);

                for (int row_offset = 0; row_offset < 3; ++row_offset)
                {
                    for (int col_offset = 0; col_offset < 3; ++col_offset)
                    {
                        if (board[row+row_offset][col+col_offset] != '.')
                        {
                            int index = board[row][col] - '0' - 1;
                            if (numbers[index] == true) return false;
                            else numbers[index] == true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; ++i)
        {
            bool rowsCheck[9] = {false};
            bool colsCheck[9] = {false};
            bool cubsCheck[9] = {false};
            for (int j = 0; j < 9; ++j)
            {
                // check row, i as row_index & j as col_index
                if (board[i][j] != '.' && checkElement(rowsCheck, board[i][j]) == false)
                    return false;

                // check col, i as col_index & j as row_index
                if (board[j][i] != '.' && checkElement(colsCheck, board[j][i]) == false)
                    return false;
                
                // check cubs, j as offset of each cubs, i as each cub
                // access board[(i/3)*3 + j/3][(i%3)*3 + j%3]
                if (board[(i/3)*3 + j/3][(i%3)*3 + j%3] != '.' && \
                    checkElement(cubsCheck, board[(i/3)*3 + j/3][(i%3)*3 + j%3]) == false)
                    return false;
            }
            return true;
        }
    }

private:
    bool checkElement(bool checks[], char ch)
    {
        bool ret = false;
        int index = ch - '0' - 1;
        if (checks[index] == false) ret = checks[index] = true;
        return ret;
    }
};
