class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        struct comp{
            bool operator()(pair<string, int>& a,pair<string, int>& b){
                if(a.second != b.second){
                    return a.second > b.second;
                }
                return a.first < b.first;
            }
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;

        for(int i =0; i<words.size(); i++){
            mp[words[i]]++;
        }

        for(auto &it: mp){
            pq.push({it.first, it.second});
            if(pq.size() > k){
                pq.pop();
            }
        }
        int i = k-1;
        vector<string>res(k);

        while(!pq.empty()){
            pair<string, int> temp = pq.top();
            res[i] = temp.first;
            pq.pop();
            i--;
        }
        return res;
    }
};
