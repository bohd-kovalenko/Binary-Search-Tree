#ifndef LAB2_4_TRIE_H
#define LAB2_4_TRIE_H

#endif //LAB2_4_TRIE_H

#include "unordered_map"
#include "string"
#include "vector"

using namespace std;

struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode *> children;

    TrieNode();
};

struct Trie {
    TrieNode *head;

public:
    Trie();

    void insert(string word);

    vector<string> findByPrefix(string prefix);

private:
    void findAllWordsWithPrefixInternal(vector<string> &result, TrieNode *node, string &word);
};