// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

// Using Brute Force naive Approach
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i <= m - n; i++)
        { // haystack

            for (int j = 0; j < n; j++)
            { // needle

                if (haystack[i + j] != needle[j])
                    break;

                if (j == n - 1)
                    return i;
            }
        }

        return -1;
    }
};

// Using KMP
class Solution
{
public:
    void computeLPS(string needle, vector<int> &lps)
    {
        int M = needle.size();
        int len = 0;

        lps[0] = 0;
        int i = 1;
        while (i < M)
        {
            if (needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle)
    {
        int N = haystack.size();
        int M = needle.size();

        vector<int> lps(M, 0);
        computeLPS(needle, lps);

        int i = 0;
        int j = 0;

        while (i < N)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == M)
            {
                return i - j;
            }
            else if (i < N && needle[j] != haystack[i])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};