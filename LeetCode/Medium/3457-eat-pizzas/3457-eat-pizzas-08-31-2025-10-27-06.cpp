class Solution {
public:
    long long maxWeight(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
       int k = n/4;

        int odd = (k+1)/2;
        int even = k-odd;

        long ans =0;
        int r= n-1;

        for(int i=0;i<odd;i++){
            ans+=arr[r];
            r--;

        }

        for(int i=0;i<even;i++){
            int f =arr[r];
            r--;
            int s = arr[r];
            r--;
            ans+=s;
        }
        return ans;
    }
};