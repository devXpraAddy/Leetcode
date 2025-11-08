class Solution {
public:
    int minimumOneBitOperations(int n) {
        // Initialize variables to keep track of the result and a flag for toggling operations
        int ans = 0, f = 0;

        // Loop through the bits of the number from the most significant bit to the least significant bit (from left to right)
        for (int i = 31; i >= 0; i--) {
            // Check if the i-th bit of the number n is set to 1
            if (((n >> i) & 1) == 1) {
                // If the flag f is 0 (indicating the start of a sequence of 1s)
                if (f == 0) {
                    // Add the calculated value to ans by left-shifting 1 to (i+1) and subtracting 1
                    ans = ans + ((1 << (i + 1))) - 1;

                    // Set the flag f to 1 to indicate the start of an alternating sequence of 1s
                    f = 1;
                } else {
                    // If the flag f is 1 (indicating an alternating sequence of 1s),
                    // subtract the calculated value from ans by left-shifting 1 to (i+1) and subtracting 1
                    ans = ans - ((1 << (i + 1)) - 1);

                    // Set the flag f to 0 to switch back to the start of a sequence of 1s
                    f = 0;
                }
            }
        }
        // Return the final result
        return ans;
    }
};

