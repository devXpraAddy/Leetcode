// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution
{
public:
    vector<vector<string>> result;
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string> &temp)
    {
        int n = s.size();
        if (idx >= s.size())
        {
            result.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        solve(s, 0, temp);
        return result;
    }
};