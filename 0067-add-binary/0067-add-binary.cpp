class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res;
        int sum = 0, carry = 0;

        while (i >= 0 || j >= 0) {
            sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            carry = sum / 2;
            res += (sum % 2) + '0';
            
        }
        if(carry != 0){
            res += '1';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
