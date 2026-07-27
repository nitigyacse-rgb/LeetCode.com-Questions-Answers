#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int idx) {
        if (idx == word.length()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // Boundary checks and character matching
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) {
            return false;
        }

        // Mark cell as visited in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 cardinal directions
        bool found = dfs(board, word, r + 1, c, idx + 1) ||
                     dfs(board, word, r - 1, c, idx + 1) ||
                     dfs(board, word, r, c + 1, idx + 1) ||
                     dfs(board, word, r, c - 1, idx + 1);

        // Backtrack: restore original character
        board[r][c] = temp;

        return found;
    }
};