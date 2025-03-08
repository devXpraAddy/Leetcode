class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0, ans = k;
        for (int i = 0; i < blocks.size(); ++i) {
            if (blocks[i] == 'W')
                count++;
            if (i >= k && blocks[i - k] == 'W')
                count--; // if we have seen more than k items then remove the
                         // items that leave the window i.e i-k th item
            if (i + 1 >= k)
                ans = min(ans, count); // if we have seen at least k item then
                                       // check for min count as answer
        }
        return min(ans, count);
    }
};