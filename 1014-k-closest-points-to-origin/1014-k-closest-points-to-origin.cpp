class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;

        for(vector<int>v: points){
            int x = v[0], y = v[1];
            int dist = x*x + y*y;
            pq.push({dist, v});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            vector<int> temp = pq.top().second;
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};