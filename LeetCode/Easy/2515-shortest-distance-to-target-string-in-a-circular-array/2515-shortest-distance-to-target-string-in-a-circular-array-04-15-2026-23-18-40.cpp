class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forwardDist = abs(i - startIndex);
                int backwardDist = n - forwardDist;
                minDist = min(minDist, min(forwardDist, backwardDist));
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};