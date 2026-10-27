#include "Trie.h"

void Trie::destroy(TrieNode* node) {
    if (!node) return;
    for (auto& cap : node->con) {
        destroy(cap.second);
    }
    delete node;
}

void Trie::insert(const std::string& tenSach) {
    (void)tenSach;
}

bool Trie::search(const std::string& tenSach) const {
    (void)tenSach;
    return false;
}

void Trie::collectWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& out) const {
    if (!node) return;
    if (node->ketThucTu) out.push_back(prefix);
    for (const auto& cap : node->con) {
        collectWords(cap.second, prefix + cap.first, out);
    }
}

std::vector<std::string> Trie::goiYTheoTienTo(const std::string& tienTo) const {
    std::vector<std::string> ketQua;
    (void)tienTo;
    return ketQua;
}
