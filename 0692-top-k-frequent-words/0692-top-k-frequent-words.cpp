class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        auto lambda= [](pair<string, int>& a, pair<string, int>& b){
            if(a.second == b.second){
                return a.first < b.first; // ascending order (opposite for heap)
            }
            return a.second > b.second; // descending order 
        };

        for(int i = 0; i<words.size(); i++){
            mp[words[i]]++;
        }

        vector<pair<string, int>> vec;

        for(auto it: mp){
            vec.push_back({it.first, it.second});
        }

        sort(vec.begin(), vec.end(), lambda);

        vector<string>res(k);

        int i=0;

        while(i<k){
            res[i] = vec[i].first;
            i++;
        }
        return res;
    }
};