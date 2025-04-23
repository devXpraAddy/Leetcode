class Solution {
public:
    int countLargestGroup(int n) {

        map<int, int> freq ;
        int sum = 0, maxSize = 0, cnt = 0 ;

        for(int i=1; i<=n; ++i) {
            sum = digitSum(i) ;
            freq[sum]++ ;
            maxSize = max(maxSize, freq[sum]) ;
        }

        for(auto& f : freq) {
            if(f.second == maxSize) {
                ++cnt ;
            }
        }

        return cnt ;

    }



private:
    int digitSum(int num) {

        int sum = 0 ;

        while(num) {
            sum += (num % 10) ;
            num /= 10 ;
        }

        return sum ;

    }
};