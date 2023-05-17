#include "Trie.h"

void Trie::insert(string word) {
    TrieNode *curr = head;
    for (int i = 0; i < word.length(); i++) {
        if (curr->children.find(word[i]) == nullptr) {
            curr->children.insert(make_pair(word[i], new TrieNode()));
            curr = curr->children.find(word[i])->second;
        } else {
            curr = curr->children.find(word[i])->second;
        }
        if (i == word.length() - 1) curr->isWord = true;
    }
}

vector<string> Trie::findByPrefix(string prefix) {
    TrieNode *curr = head;
    vector<string> result;
    for (int i = 0; i < prefix.length(); i++) {
        if (curr == nullptr || curr->children.find(prefix[i]) == nullptr) return result;
        curr = curr->children.find(prefix[i])->second;
    }
    findAllWordsWithPrefixInternal(result, curr, prefix);
    return result;
}

Trie::Trie() {
    head = new TrieNode();
}

void Trie::findAllWordsWithPrefixInternal(vector<string> &result, TrieNode *node, string &word) {
    if (node == nullptr) return;
    if (node->isWord) result.push_back(word);
    for (const auto &pair: node->children) {
        string nextWord = word + pair.first;
        findAllWordsWithPrefixInternal(result, pair.second, nextWord);
    }
}

TrieNode::TrieNode() {
    isWord = false;
}
