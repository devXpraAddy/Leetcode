// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

// resursion
class Solution
{
public:
    unordered_set<string> st;
    int n;
    bool solve(string s, int i)
    {
        if (i >= n)
        {
            return true;
        }
        if (st.find(s) != st.end())
        { // if the word is already present then we won't break the string
            return true;
        }
        for (int l = 1; l <= n; l++)
        {
            string temp = s.substr(i, l);
            if (st.find(temp) != st.end() && solve(s, i + l))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();
        for (int i = 0; i < wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        return solve(s, 0);
    }
};

// Approach-1 (Recur + Memoiz) -
// T.C :  O(n * 2^n) Because at each index, we eaither split it or not and substr also takes O(n)
class Solution
{
public:
    int t[301];
    unordered_set<string> st;
    bool solve(string s, int idx)
    {
        if (idx >= s.size())
            return true;

        if (t[idx] != -1)
        {
            return t[idx];
        }

        if (st.find(s) != st.end())
            return t[idx] = true;

        for (int l = 1; l < s.size(); l++)
        {
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(s, idx + l))
            {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(t, -1, sizeof(t));
        for (int i = 0; i < wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        return solve(s, 0);
    }
};

// Approach-2 (Bottom Up DP)
class Solution
{
public:
    bool solve(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n + 1, false);
        /*
            t[i] = True;
            It means that for string of length i, its possible to break
            the word such that broken words are in wordDict
        */

        t[0] = true; // string of length 0 is always true

        for (int i = 1; i <= n; i++)
        {
            // we choose different point (j) to break
            for (int j = 0; j < i; j++)
            {
                string temp = s.substr(j, i - j);

                if (st.count(temp) && t[j])
                {
                    /*
                        It means from s[j...i] is in wordDict
                        And, t[j] = true means s[0...j] could
                        also be broken correctly
                    */

                    t[i] = true;
                    break;
                }
            }
        }
        return t[n]; // length n
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solve(s, wordDict);
    }
};
