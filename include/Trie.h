#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <map>
class Trie {
private:
    struct TrieNode {
        std::map<char, TrieNode*> con;
        bool ketThucTu; 
        TrieNode() : ketThucTu(false) {}
    };
    TrieNode* root;
    void destroy(TrieNode* node);
    void collectWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& out) const;
public:
    Trie() : root(new TrieNode()) {}
    Trie() { destroy(root); }
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    void insert(const std::string& tenSach);
    bool search(const std::string& tenSach) const;          
    std::vector<std::string> goiYTheoTienTo(const std::string& tienTo) const; 

