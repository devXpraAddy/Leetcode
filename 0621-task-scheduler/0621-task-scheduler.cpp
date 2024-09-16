class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        int time = 0;

        priority_queue<int> pq;

        for (auto it : mp) {
            if (it.second > 0) {
                pq.push(it.second);
            }
        }
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int &f : temp){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};
