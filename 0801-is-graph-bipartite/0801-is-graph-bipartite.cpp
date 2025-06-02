class Solution {
private: 
    bool bfs(int start, vector<vector<int>>&adj, vector<int>& color){
        color[start] = 0;
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // int siz = adj.size();
        vector<int> color(n, -1);

        for(int i =0; i<n; i++){
            if(color[i] == -1){
                if(bfs(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};
