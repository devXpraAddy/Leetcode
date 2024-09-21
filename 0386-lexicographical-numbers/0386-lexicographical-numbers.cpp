class Solution {
public:
    void solve(int curr, int n , vector<int>& result){
        if(curr > n) return ;
        result.push_back(curr);

        for(int nextval = 0; nextval <=9; nextval++){
            int val = curr*10 + nextval;
            if(val >n) return;
            solve(val, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i =1; i<=9; i++){
            solve(i, n, result);
        }
        return result;
    }
};