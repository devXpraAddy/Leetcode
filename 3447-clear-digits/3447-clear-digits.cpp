class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string res = "";
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9' && !st.empty()) {
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