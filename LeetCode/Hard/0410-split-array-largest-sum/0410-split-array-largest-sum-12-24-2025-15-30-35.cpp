class Solution {
private:
int countPainters(vector<int>&boards, long long x){
    long long painter =1, val =0;
    for(int i = 0; i<boards.size(); i++){
        if(boards[i] + val <= x){
            val += boards[i];
        }else{
            painter++;
            val = boards[i];
        }
    }
    return painter;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    long long low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);
    long long ans = 0;

    while(low<=high){
        long long mid = low + (high - low)/2;

        if(countPainters(boards, mid) <= k){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
public:
    int splitArray(vector<int>& nums, int k) {
        return findLargestMinDistance(nums, k);
    }
};