/*
    Sample Input 1 :
        4
        abc def ghi cba
        de
    Sample Output 2 :
        true
    Sample Input 2 :
        4
        abc def ghi hg
        hi
    Sample Output 2 :
        true
    Sample Input 3 :
        4
        abc def ghi hg
        hif
    Sample Output 3 :
        false
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(this->root, word))
        {
            this->count++;
        }
    }

    bool searchWord(TrieNode *root, string pattern)
    {
        if (pattern.size() == 0)
            return true;

        int i = pattern[0] - 'a';
        if (root->children[i] != NULL)
        {
            return searchWord(root->children[i], pattern.substr(1));
        }
        else
            return false;
    }

    bool searchWord(string pattern)
    {
        return searchWord(this->root, pattern);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        // Write your code here

        // insert all the word as suffix trie
        for (int i{0}; i < vect.size(); i++)
        {
            string word = vect[i];
            for (int j{0}; j < word.size(); j++)
            {
                this->insertWord(word);
                word = word.substr(1);
            }
        }

        // search for the pattern
        return searchWord(pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}