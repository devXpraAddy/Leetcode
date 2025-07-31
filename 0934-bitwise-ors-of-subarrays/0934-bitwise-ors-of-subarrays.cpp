class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st,prev,curr;
        for(int i=0;i<arr.size();i++){
            //take or from all prev computed sums
            curr.insert(arr[i]);
            for( auto x:prev){
                curr.insert(x|arr[i]);
            }
            //make curr as prev & add values to res
            prev=curr;
            curr.clear();
            for(auto x:prev){
                st.insert(x);
            }
        }
        return st.size();
        
    }
};

    