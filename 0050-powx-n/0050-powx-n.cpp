class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to prevent overflow when n = INT_MIN
        long long N = n;
        
        // Handle negative power
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        
        double result = 1.0;
        double currentProduct = x;
        
        while (N > 0) {
            // If N is odd, multiply the current product into result
            if (N % 2 == 1) {
                result *= currentProduct;
            }
            // Square the base and halve the exponent
            currentProduct *= currentProduct;
            N /= 2;
        }
        
        return result;
    }
};