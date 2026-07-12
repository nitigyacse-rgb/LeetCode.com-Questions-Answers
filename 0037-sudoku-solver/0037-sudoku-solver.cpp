class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    vector<pair<int,int>> empty;

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx == empty.size())
            return true;

        int r = empty[idx].first;
        int c = empty[idx].second;
        int b = (r / 3) * 3 + (c / 3);

        for (int num = 1; num <= 9; num++) {
            if (!row[r][num] && !col[c][num] && !box[b][num]) {
                board[r][c] = char(num + '0');
                row[r][num] = col[c][num] = box[b][num] = true;

                if (solve(board, idx + 1))
                    return true;

                board[r][c] = '.';
                row[r][num] = col[c][num] = box[b][num] = false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        empty.clear();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    empty.push_back({i, j});
                } else {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    box[(i / 3) * 3 + (j / 3)][num] = true;
                }
            }
        }

        solve(board, 0);
    }
};