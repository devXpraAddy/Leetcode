// https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isOverlap(vector<int> &i1, vector<int> &i2)
    {
        if (i2[0] <= i1[1])
            return true;
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedList;

        vector<int> prev = intervals[0];

        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];
            if (isOverlap(prev, curr))
            {
                prev[1] = max(prev[1], curr[1]);
            }
            else
            {
                mergedList.push_back(prev);
                prev = curr;
            }
        }
        mergedList.push_back(prev);
        return mergedList;
    }
};