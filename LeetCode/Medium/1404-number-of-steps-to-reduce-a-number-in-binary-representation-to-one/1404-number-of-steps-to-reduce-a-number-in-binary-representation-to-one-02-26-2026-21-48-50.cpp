class Solution {
public:
    int numSteps(string s) {
        int n = (int)s.size();
        int carry = 0;
        int steps = 0;

        // process from rightmost to index 1 (stop before MSB)
        for (int i = n - 1; i >= 1; --i) {
            int bit = (s[i] - '0') + carry;

            if (bit == 0 || bit == 2) {
                steps += 1;
            } else { 
                steps += 2;
                carry = 1;
            }
        }

        // if carry remains at MSB, it creates an extra step (e.g., 111 + carry -> 1000)
        return steps + carry;    
    }
};