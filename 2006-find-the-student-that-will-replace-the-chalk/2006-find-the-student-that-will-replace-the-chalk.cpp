class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; //Total chalks required in one iteration
        for(int &chalkReq : chalk) { //O(n)
            totalChalkSum += chalkReq;
        }

        //Number of full iteration possible = k/totalChalkSum

        int remainChalk = k%totalChalkSum;

        for(int i = 0; i < n; i++) { //O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};

