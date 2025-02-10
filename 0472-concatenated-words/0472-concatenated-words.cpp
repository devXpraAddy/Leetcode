
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        // Initialize a HashSet to store all words for quick lookup
        unordered_set<string> wordSet(words.begin(), words.end());
        
        // Initialize a vector to store the concatenated words
        vector<string> concatenatedWords;
        
        // Iterate over each word in the list
        for (const string& word : words) {
            
            // If the word can be formed by concatenating other words, add it to the result
            if (canForm(word, wordSet)) {
                concatenatedWords.push_back(word);
            }
        }
        
        // Return the list of concatenated words
        return concatenatedWords;
    }

private:
    bool canForm(const string& word, unordered_set<string>& wordSet) {
        
        // If the word is empty, it cannot be formed
        if (word.empty()) return false;
        
        // Initialize a vector to store whether a prefix can be formed
        vector<bool> dp(word.size() + 1, false);
        
        // An empty prefix can always be formed
        dp[0] = true;
        
        // Iterate over each position in the word
        for (int i = 1; i <= word.size(); ++i) {
            
            // Check each prefix ending at position i
            for (int j = (i == word.size() ? 1 : 0); j < i; ++j) {
                
                // If the prefix can be formed and the suffix is in the set, mark position i as formable
                if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        // Return whether the entire word can be formed
        return dp[word.size()];
    }
};
