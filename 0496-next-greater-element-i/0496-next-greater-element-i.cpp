class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> ans;
        int n = nums2.size();

        for(int i = n-1; i>=0; i--){
            int elm = nums2[i];
            while(!st.empty() && st.top() <= elm){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            mp.insert({elm, res});
            st.push(elm);
        }
        for(auto x: nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};
