#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;

        while (val <= n * n) {
            // Fill top row (left to right)
            for (int j = left; j <= right; ++j) {
                matrix[top][j] = val++;
            }
            top++;

            // Fill right column (top to bottom)
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = val++;
            }
            right--;

            // Fill bottom row (right to left)
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = val++;
            }
            bottom--;

            // Fill left column (bottom to top)
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = val++;
            }
            left++;
        }

        return matrix;
    }
};