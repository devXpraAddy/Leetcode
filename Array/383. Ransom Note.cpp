// https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < magazine.size(); i++)
        {
            mp[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (mp[ransomNote[i]] > 0)
            {
                mp[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// When is question it is given that it contain only lower case english alphabets
// then we can further optimize it
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};

        for (int i = 0; i < magazine.size(); i++)
        {
            count[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (count[ransomNote[i] - 'a'] > 0)
            {
                count[ransomNote[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// or
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};

        for (auto it : magazine)
        {
            count[it - 'a']++;
        }
        for (auto it : ransomNote)
        {
            if (count[it - 'a'] > 0)
            {
                count[it - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};