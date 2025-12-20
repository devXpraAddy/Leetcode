class Solution {
private:
    int findMax(vector<int>&piles){
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long findTotalHours(vector<int>&piles, int hours){
        long long totalHours = 0;

        for(int i =0; i<piles.size(); i++){
            totalHours+= ceil((double)piles[i]/hours);
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        int ans = high;

        while(low <= high){
            long long mid = low + (high - low)/2;
            long long totalHours = findTotalHours(piles, mid);
            if(totalHours <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};