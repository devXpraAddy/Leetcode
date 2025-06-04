class Solution {
private:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>& graph, vector<int>&check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, graph, check) == true) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>vis(N);
        vector<int>pathVis(N);
        vector<int>check(N);

        vector<int>res;

        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, graph, check);
            }
        }
        for(int i =0;i<N; i++){
            if(check[i] ==1){
                res.push_back(i);
            }
        }
        return res;
    }
};
