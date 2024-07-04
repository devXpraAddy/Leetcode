// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // If the intervals list is empty, return it as is
        if (intervals.empty())
            return intervals;

        // Sort intervals based on start times
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        // List to hold the merged intervals
        vector<vector<int>> mergedList;
        // Initialize the previous interval to the first one in the sorted list
        vector<int> prev = intervals[0];

        // Iterate through the sorted intervals starting from the second interval
        for (size_t i = 1; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];
            // Check if the current interval overlaps with the previous interval
            if (doIntervalsOverlap(prev, curr))
            {
                // Merge the intervals by updating the end time of the previous interval
                prev[1] = max(prev[1], curr[1]);
            }
            else
            {
                // If they do not overlap, add the previous interval to the merged list
                mergedList.push_back(prev);
                // Update the previous interval to the current interval
                prev = curr;
            }
        }
        // Add the last interval
        mergedList.push_back(prev);

        // Return the list of merged intervals
        return mergedList;
    }

private:
    // Function to check if two intervals overlap
    bool doIntervalsOverlap(const vector<int> &i1, const vector<int> &i2)
    {
        // Intervals overlap if the start of the second interval is less than or equal to the end of the first interval
        if (i2[0] > i1[1])
            return false;
        return true;
    }
};
