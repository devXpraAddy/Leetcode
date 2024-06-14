// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int i = 0, j = 0;
        int ans = 0;

        while (i < seats.size() && j < students.size())
        {
            ans += abs(seats[i] - students[i]);
            i++;
            j++;
        }
        return ans;
    }
};