// https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07

class Solution
{
public:
    string findRoot(string &word, unordered_set<string> &st)
    {
        for (int l = 1; l <= word.size(); l++)
        {
            string root = word.substr(0, l);
            if (st.count(root))
            {
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);

        string word;
        string result;

        while (getline(ss, word, ' '))
        {
            result += findRoot(word, st) + " ";
        }
        result.pop_back();
        return result;
    }
};
// This can also be done with Tries