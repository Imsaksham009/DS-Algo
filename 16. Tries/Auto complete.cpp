/*
    Sample Input 1 :
    7
    do dont no not note notes den
    no
    Sample Output 2 :
    no
    not
    note
    notes
    Sample Input 2 :
    7
    do dont no not note notes den
    de
    Sample Output 2 :
    den
    Sample Input 3 :
    7
    do dont no not note notes den
    nom

*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void print(TrieNode* root, string w)
    {
        if(root->isTerminal)
        {
            cout<<w<<endl;
        }
        for(int i{0};i<26;i++)
        {
            if(root->children[i] != NULL)
            {

                print(root->children[i],w+(root->children[i]->data));
                // w.pop_back();
            }
        }
        
    }

    void helper(TrieNode* root,string pattern,string w="")
    {
        if(pattern.size() == 0)
        {
            print(root,w);
        }
        else{
        int i = pattern[0] - 'a';
        if(root->children[i] != NULL)
            helper(root->children[i],pattern.substr(1),w+pattern[0]);
        else return;
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here

        for(int i{0};i<input.size();i++){
            this->insertWord(input[i]);
        }

        string w = pattern;
        helper(this->root,pattern);

    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}