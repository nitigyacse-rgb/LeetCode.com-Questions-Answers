class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // A mask with the lower n bits set to 1
        int upperLimit = (1 << n) - 1;
        
        backtrack(0, 0, 0, upperLimit, count);
        return count;
    }

private:
    void backtrack(int cols, int diag1, int diag2, int upperLimit, int& count) {
        // Base case: All rows are filled
        if (cols == upperLimit) {
            count++;
            return;
        }

        // Get all available positions in the current row
        // (1 represents an available position)
        int availablePositions = upperLimit & ~(cols | diag1 | diag2);

        while (availablePositions > 0) {
            // Extract the lowest set bit (position for placing a queen)
            int position = availablePositions & -availablePositions;

            // Clear the bit from available positions
            availablePositions -= position;

            // Recurse to the next row with updated collision masks
            backtrack(
                cols | position,
                (diag1 | position) << 1,
                (diag2 | position) >> 1,
                upperLimit,
                count
            );
        }
    }
};