class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long num = 0;

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Determine sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Skip leading zeros
        while (i < n && s[i] == '0') {
            i++;
        }

        // Step 4: Convert digits and check overflow
        for (; i < n; i++) {
            if (!isdigit(s[i])) break;
            
            int digit = s[i] - '0';
            num = num * 10 + digit;

            // Early overflow detection
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && num > static_cast<long long>(INT_MAX) + 1) {
                return INT_MIN;
            }
        }

        return static_cast<int>(sign * num);
    }
};
