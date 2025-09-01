class Solution {
private:
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i, string& s, vector<string>&path, vector<vector<string>>&res){
        if(i == s.size()){
            res.push_back(path);
        }
        for(int j = i; j<s.size(); j++){
            if(isPalindrome(i, j, s)){
                path.push_back(s.substr(i , j-i+1));
                solve(j+1, s, path, res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        solve(0, s, path, res);
        return res;
    }
};