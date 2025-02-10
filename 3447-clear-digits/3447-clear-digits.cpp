class Solution {
public:
    bool isDigit(char s) {
        if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4' ||
            s == '5' || s == '6' || s == '7' || s == '8' || s == '9') {
            return true;
        }
        return false;
    }
    string clearDigits(string s) {
        stack<char> st;
        string res = "";
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (isDigit(s[i]) == true && !st.empty() && isDigit(st.top()) == false) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};