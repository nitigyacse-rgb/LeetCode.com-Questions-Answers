class Solution {
private:
    // Subroutine from LeetCode 84: Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxOverallArea = 0;

        for (int r = 0; r < rows; r++) {
            // Update heights array for current row
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0; // Reset height if there's a 0
                }
            }

            // Find maximum rectangle area for histogram of current row
            maxOverallArea = max(maxOverallArea, largestRectangleArea(heights));
        }

        return maxOverallArea;
    }
};