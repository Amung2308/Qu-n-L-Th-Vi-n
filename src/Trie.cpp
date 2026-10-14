#include "Trie.h"

void Trie::destroy(TrieNode* node) {
    if (!node) return;
    for (auto& cap : node->con) {
        destroy(cap.second);
    }
    delete node;
}

void Trie::insert(const std::string& tenSach) {
    // TODO (Tuan 8): duyet tung ky tu cua tenSach tu root, neu chua co nhanh thi tao
    // TrieNode moi, cuoi cung danh dau ketThucTu = true tai node cuoi.
    (void)tenSach;
}

bool Trie::search(const std::string& tenSach) const {
    // TODO (Tuan 8): duyet theo tung ky tu, neu thieu nhanh nao thi tra ve false;
    // het chuoi thi tra ve node->ketThucTu.
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
    // TODO (Tuan 8): di xuong theo tung ky tu cua tienTo tu root de tim node goc cua
    // nhanh, neu khong du nhanh thi tra ve rong; neu co, goi collectWords() tu do.
    std::vector<std::string> ketQua;
    (void)tienTo;
    return ketQua;
}
