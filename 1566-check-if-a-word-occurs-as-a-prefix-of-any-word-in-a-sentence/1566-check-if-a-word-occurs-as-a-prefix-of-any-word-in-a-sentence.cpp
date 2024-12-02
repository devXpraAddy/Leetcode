//T.C : O(words * n), words = total number of words, n = length of searchWord
//S.C : O(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);

        string token = "";
        int index = 1;
        while(getline(ss, token, ' ')) {
            if(token.find(searchWord, 0) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};
