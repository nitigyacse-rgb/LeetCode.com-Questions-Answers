class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int totalSteps = m + n - 2;
        int k = min(m - 1, n - 1); // Use smaller k to minimize loop iterations
        
        for (int i = 1; i <= k; i++) {
            ans = ans * (totalSteps - k + i) / i;
        }
        
        return static_cast<int>(ans);
    }
};