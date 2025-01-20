class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;
        vector<int>res;

        for(int i =0 ; i<arr.size(); i++){
            int cnt = 0;
            int num = arr[i];
            while(num >0){
                num = num & (num-1);
                cnt++;
            }
            vec.push_back({cnt, arr[i]});
        }
        sort(vec.begin(), vec.end());

        for(auto& x: vec){
            res.push_back(x.second);
        }
        return res;
    }
};