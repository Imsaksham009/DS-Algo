#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
private:
    char word;
    TrieNode **children;
    bool isTerminal;

public:
    TrieNode(char word)
    {
        this->word = word;
        children = new TrieNode *[26];
        for (int i{0}; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        isTerminal = false;
    }
    friend class Trie;
};

class Trie
{
private:
    TrieNode *root;

    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            insertWord(root->children[index], word.substr(1));
        }
        else
        {
            TrieNode *newChild = new TrieNode(word[0]);
            root->children[index] = newChild;
            insertWord(newChild, word.substr(1));
        }
    }

    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
                return true;
            else
                return false;
        }

        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return searchWord(root->children[index], word.substr(1));
        }
        else
            return false;
    }

    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'a';

            TrieNode *child;

            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
                return;

            removeWord(child, word.substr(1));

            if (child->isTerminal == false)
            {
                for (int i{0}; i < 26; i++)
                {
                    if (child->children[i] != NULL)
                    {
                        return;
                    }
                }
                delete child;
                root->children[index] = NULL;
            }
        }
    }

public:
    Trie()
    {
        this->root = new TrieNode('\0');
    }

    void insertWord(string word)
    {
        insertWord(this->root, word);
    }

    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};