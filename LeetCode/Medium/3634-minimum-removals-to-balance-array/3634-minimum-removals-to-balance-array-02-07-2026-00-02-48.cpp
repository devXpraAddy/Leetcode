class Solution {
public:
    int BN(vector<int>& arr, int i , long long target) {
        int low = i;
        int high = arr.size() - 1;
        int ans = INT_MIN;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if(target >= arr[mid]){
                ans = max(mid, ans);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }

    int minRemoval(vector<int>& temp, int k) {
        sort(temp.begin(), temp.end());
        int n = temp.size();
        if(n == 1) return 0;
        int ans = INT_MAX;
        for (int i = 0; i < temp.size(); i++) {
            int right = BN(temp , i , 1LL * k * temp[i]);
            if(right == i){
                ans = min(ans, n - 1);
            }else{
                ans = min(ans, i + ((n - 1) - right));
            }
        }

        return ans;
    }
};