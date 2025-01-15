class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2); // Count set bits in num2
        int x = 0;
        
        // Set bits in x based on num1's set bits
        for (int i = 31; i >= 0 && setBitsNum2 > 0; --i) {
            if ((num1 >> i) & 1) {
                x |= (1 << i);
                setBitsNum2--;
            }
        }
        
        // If there are still bits to set, set them from the least significant bits
        for (int i = 0; i <= 31 && setBitsNum2 > 0; ++i) {
            if (!((x >> i) & 1)) {
                x |= (1 << i);
                setBitsNum2--;
            }
        }
        
        return x;
    }
};
