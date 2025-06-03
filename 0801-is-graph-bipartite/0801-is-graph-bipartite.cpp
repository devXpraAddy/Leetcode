class Solution {
private:
    bool dfs(int start, vector<vector<int>>& graph, vector<int> &color){

            for(auto it: graph[start]){
                if(color[it] == -1){
                    color[it] = !color[start];
                    if(dfs(it, graph, color) == false) return false;
                }else if(color[it] == color[start]){
                    return false;
                }
            }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n, -1);

        for(int i =0;i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(dfs(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};