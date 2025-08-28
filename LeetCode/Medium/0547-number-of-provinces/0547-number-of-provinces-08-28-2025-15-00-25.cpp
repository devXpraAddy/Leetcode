class Solution {
private:
    void solve(int node, vector<int>& vis, vector<vector<int>>&adj){
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] =1;
                solve(it, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt =0;
        vector<int>vis(n, 0);
        for(int i =0;i<n; i++){
            if(!vis[i]){
                solve(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};