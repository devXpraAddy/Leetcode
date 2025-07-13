class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        struct comp{
            bool operator()(pair<int,int>& a, pair<int,int>& b){
                return a.second > b.second; // min-heap
            }
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(pair<int,int> it: mp){
            pq.push({it.first, it.second});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;

        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            res.push_back(temp.first);
        }
        return res;
    }
};