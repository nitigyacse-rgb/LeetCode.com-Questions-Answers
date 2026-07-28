class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            // Use 0 as a sentinel height at index n to pop remaining elements from stack
            int currentHeight = (i == n) ? 0 : heights[i];

            // Maintain monotonic increasing order in the stack
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // Determine width: distance between current index and new stack top
                int w = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};