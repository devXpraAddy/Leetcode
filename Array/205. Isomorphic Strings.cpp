// https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++)
        {
            int ch1 = s[i];
            int ch2 = t[i];
            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1))
            {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};