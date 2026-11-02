class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> grids;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val == '.') continue;
                if (rows[i].count(val)) return false;
                if (cols[j].count(val)) return false;
                int grid = (i / 3) * 3 + (j / 3);
                if (grids[grid].count(val)) return false;

                rows[i].insert(val);
                cols[j].insert(val);
                grids[grid].insert(val);
            }
        }
        return true;  
    }
};
