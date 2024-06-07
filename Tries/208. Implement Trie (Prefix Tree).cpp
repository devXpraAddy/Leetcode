// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie
{
public:
    struct trieNode
    {
        bool isEndOfWord;
        trieNode *children[26];
    };

    trieNode *
    getNode()
    {
        trieNode *newNode = new trieNode();
        newNode->isEndOfWord = NULL;
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode *root;

    Trie() { root = getNode(); }

    void insert(string word)
    {                             // apple
        trieNode *crawler = root; // crowler pointer pointing to root
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
            {
                crawler->children[idx] = getNode(); // creating node for 'a'
            }
            crawler = crawler->children[idx]; // increasing the crawler
        } // by end of this for loop crawler will be pointing to "e"
        crawler->isEndOfWord = true; // 'e'
    }

    bool search(string word)
    {
        trieNode *crawler = root; // crowler pointer pointing to root
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
            {
                return false; // craawler->children[idx] = getNode(); //
                              // creating node for 'a'
            }
            crawler = crawler->children[idx]; // increasing the crawler
        } // by end of this for loop crawler will be pointing to "e"
        if (crawler != NULL && crawler->isEndOfWord == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        trieNode *crawler = root; // crowler pointer pointing to root
        int i = 0;
        for (; i < prefix.size(); i++)
        {
            char ch = prefix[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
            {
                return false; // craawler->children[idx] = getNode(); //
                              // creating node for 'a'
            }
            crawler = crawler->children[idx]; // increasing the crawler
        } // by end of this for loop crawler will be pointing to "e"
        if (i == prefix.size())
        { // means that it has got all the elements of the prefix
            return true;
        }
        else
        {
            return false;
            vs
        }
    }
};

// important thing is you should know how to write insert and search

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */