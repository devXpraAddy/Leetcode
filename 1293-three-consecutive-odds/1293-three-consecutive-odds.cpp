class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n= arr.size();
        int i =0;
        int count = 0;
        while(i<n){
            if(arr[i] % 2 != 0 && count <3){
                count++;
                if(count ==3){
                    return true;
                }
            }else{
                count =0;
            }
            i++;
        }
        return false;
    }
};