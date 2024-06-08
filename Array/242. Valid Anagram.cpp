// https://leetcode.com/problems/valid-anagram/description/

// Using Hash Table
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        // Count the frequency of characters in string s
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        // Decrement the frequency of characters in string t
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]--;
        }
        // Check if any character has non-zero frequency
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// Using sorting
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// Using Hash Table (Using Array)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int count[26] = {0};

        // Count the frequency of characters in string s
        for (char x : s)
        {
            count[x - 'a']++;
        }

        // Decrement the frequency of characters in string t
        for (char x : t)
        {
            count[x - 'a']--;
        }

        // Check if any character has non-zero frequency
        for (int val : count)
        {
            if (val != 0)
            {
                return false;
            }
        }

        return true;
    }
};