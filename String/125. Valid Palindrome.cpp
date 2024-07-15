// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isAlphaNum(char s)
    {
        if ((s >= 'a' && s <= 'z') || (s >= '0' && s <= '9') || (s >= 'A' && s <= 'Z'))
        {
            return true;
        }
        return false;
    }
    char toLower(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            return c + ('a' - 'A');
        }
        return c;
    }

    bool isPalindrome(string s)
    {
        int n = s.size();
        string clear;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (isAlphaNum(c))
            {
                clear += toLower(c);
            }
        }
        int left = 0;
        int right = clear.size() - 1;
        while (left < right)
        {
            if (clear[left] != clear[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
