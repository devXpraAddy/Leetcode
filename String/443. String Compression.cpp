// https://leetcode.com/problems/string-compression/description/

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while (i < n)
        {
            int count = 0;
            char curr_char = chars[i];
            // find count of duplicates
            while (i < n && chars[i] == curr_char)
            {
                count++;
                i++;
            }
            // Do the assign work
            chars[index] = curr_char;
            index++;

            if (count > 1)
            {
                string count_str = to_string(count);
                for (int i = 0; i < count_str.size(); i++)
                {
                    chars[index] = count_str[i];
                    index++;
                }
            }
        }
        return index;
    }
};
