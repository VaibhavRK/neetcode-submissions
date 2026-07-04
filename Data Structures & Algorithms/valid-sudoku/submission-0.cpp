class Solution {
public:

    bool checkSudoku(vector<vector<int>>& board, unordered_set<int> row[], unordered_set<int> col[], int x, int y){
        if(x >= 9 || y >= 9) return true;

        bool flag = false;
        if(!board[x][y]){
            flag |= checkSudoku(board, row, col, x+1, y);
            flag |= checkSudoku(board, row, col, x+1, y+1);
            flag |= checkSudoku(board, row, col, x, y+1);

            return flag;
        }
        for(int i=1;i<=9;i++){
            if(row[x].find(i) != row[x].end()) continue;
            if(col[y].find(i) != col[y].end()) continue;
            row[x].insert(i);
            col[y].insert(i);

            flag |= checkSudoku(board, row, col, x+1, y);
            flag |= checkSudoku(board, row, col, x+1, y+1);
            flag |= checkSudoku(board, row, col, x, y+1);

            row[x].erase(i);
            col[y].erase(i);
        }

        return flag;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // Skip empty cells
                if (board[r][c] == '.') continue;
                
                // Convert char '1'-'9' to index 0-8
                int num = board[r][c] - '1';
                
                // Calculate which of the 9 3x3 boxes we are in
                int boxIndex = (r / 3) * 3 + (c / 3);
                
                // If the number has already been seen in the row, col, or box, it's invalid
                if (row[r][num] || col[c][num] || box[boxIndex][num]) {
                    return false;
                }
                
                // Mark the number as seen
                row[r][num] = 1;
                col[c][num] = 1;
                box[boxIndex][num] = 1;
            }
        }
        
        return true;
    }
};
