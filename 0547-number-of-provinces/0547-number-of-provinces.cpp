class Solution {
public:
    void solve(int node, vector<int>&vis, vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto it: adj[val]){
                if(!vis[it]){
                    vis[it] =1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>>adj(n);

        for(int i = 0; i<n; i++){
            for(int j =i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int sizee = adj.size();
        vector<int>vis(sizee, 0);
        int cnt = 0;

        for(int i =0; i<sizee; i++){
            if(!vis[i]){
                cnt++;
                solve(i, vis, adj);
            }
        }
        return cnt;
    }
};

