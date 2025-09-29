class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        
        int fraction = n;

        while (fraction > 1) {
            if (fraction % 2 != 0) {
                return false;
            }
            
            fraction = fraction / 2;
        }
        return true;
    }
};