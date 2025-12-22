class Solution {
private:
    int dayReq(vector<int>&weights, int capacity){
        int days = 1, load =0;

        for(int i =0;i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }
    int findMax(vector<int>&weights){
        int maxi = INT_MIN;

        for(int i =0; i<weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int findSum(vector<int>&weights){
        int sum = 0;
        for(int i =0;i<weights.size(); i++){
            sum += weights[i];
        }
        return sum;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = findSum(weights);

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(dayReq(weights, mid) <= days){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};