class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

            auto comp = [&](pair<char, int>& a, pair<char, int> & b){
                return a.second < b.second;
            };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }

        string res = "";

        while (!pq.empty()) {
            pair<char, int> temp = pq.top();
            pq.pop();
            res += string(temp.second, temp.first);
        }
        return res;
    }
};