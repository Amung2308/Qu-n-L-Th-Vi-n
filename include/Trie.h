#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <map>

// CTDL tu tim hieu (muc 5, lua chon 1): Trie - dung cho tim sach theo tien to ten
// (autocomplete) - muc 3.5. Cai dat tu dau (from scratch), khong dung thu vien co san.
//
// Ghi chu: dung std::map<char, TrieNode*> thay vi mang con tro co dinh 26 chu cai,
// vi ten sach tieng Viet co the chua chu hoa/thuong, so, dau cach... De don gian,
// ban co the chuan hoa chuoi (vd: chuyen thuong, bo dau cau) truoc khi insert/search -
// day la phan co the mo rong them o Tuan 8-9 neu muon nang cao chat luong goi y.
class Trie {
private:
    struct TrieNode {
        std::map<char, TrieNode*> con;
        bool ketThucTu;  // danh dau mot ten sach hoan chinh ket thuc tai day

        TrieNode() : ketThucTu(false) {}
    };

    TrieNode* root;

    void destroy(TrieNode* node);
    void collectWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& out) const;

public:
    Trie() : root(new TrieNode()) {}
    ~Trie() { destroy(root); }

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const std::string& tenSach);
    bool search(const std::string& tenSach) const;          // tim chinh xac
    std::vector<std::string> goiYTheoTienTo(const std::string& tienTo) const; // autocomplete
};

#endif // TRIE_H
