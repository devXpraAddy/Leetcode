// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution
{
public:
    bool isOverlap(vector<int> &i1, vector<int> &i2)
    {
        if (i2[0] < i1[1])
            return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        vector<int> prev = intervals[0];
        int count = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];

            if (isOverlap(prev, curr))
            {
                count++;
                if (prev[1] >= curr[1])
                {
                    prev = curr;
                }
            }
            else
            {
                prev = curr;
            }
        }
        return count;
    }
};
