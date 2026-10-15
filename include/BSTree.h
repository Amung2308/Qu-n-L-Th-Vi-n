#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include "Sach.h"

// Cay nhi phan tim kiem (BST) thuong, KHONG tu can bang.
// Ap dung: in danh muc sach theo ten, duyet in-order (muc 4, dong 2).
class BSTree {
private:
    struct Node {
        Sach data;
        Node* left;
        Node* right;
        Node(const Sach& s) : data(s), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertNode(Node* node, const Sach& sach);
    void inOrderTraverse(Node* node, std::vector<Sach>& out) const;
    void destroy(Node* node);

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { destroy(root); }

    BSTree(const BSTree&) = delete;
    BSTree& operator=(const BSTree&) = delete;

    void insert(const Sach& sach);
    // Tra ve danh sach Sach theo thu tu tang dan cua ten sach.
    std::vector<Sach> inOrder() const;
};

#endif // BSTREE_H
