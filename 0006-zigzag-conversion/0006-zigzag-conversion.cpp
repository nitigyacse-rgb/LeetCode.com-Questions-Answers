#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: If there's only 1 row, or the string is shorter than the rows,
        // the zigzag pattern doesn't alter the character order.
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }

        // Create an array of strings for each row
        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        // Distribute characters to their respective rows
        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction when hitting the top or bottom boundary
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};