#include <vector>
#include <string>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        // Trackers for safe placement in O(1) time
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // row - col + (n - 1)
        vector<bool> diag2(2 * n - 1, false); // row + col
        
        backtrack(0, n, board, cols, diag1, diag2, result);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, 
                   vector<vector<string>>& result) {
        // Base case: If all queens are placed
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            // Check if column or diagonals are under attack
            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Recurse to next row
            backtrack(row + 1, n, board, cols, diag1, diag2, result);

            // Backtrack: Remove queen
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};