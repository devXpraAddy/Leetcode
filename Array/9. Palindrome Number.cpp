// Unique approach
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("-ffloat-store")

class Solution
{
public:
    bool isPalindrome(int x)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        string str_x = to_string(x);
        vector<char> tokens;

        for (char c : str_x)
        { // Tockenization
            tokens.push_back(c);
        }

        int left = 0;
        int right = str_x.size() - 1;

        while (left < right)
        {
            if (str_x[left] != str_x[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Basic Approach

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0)
        {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};
