class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int>pq;
        int res = 0;


        for(int i =0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        for(auto it: mp){
            pq.push(it.second);     
        }

        while(!pq.empty()){
            vector<int>temp;

            for(int i =1 ;i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                } 
            }
            for(auto f: temp){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                res+= temp.size();
            }else{
                res+= n+1;
            }
        }
        return res;
    }
};