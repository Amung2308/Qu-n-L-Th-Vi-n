#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include <utility>

// Cay nhi phan tim kiem (BST) thuong, KHONG tu can bang.
// Ap dung: in danh muc sach theo ten, duyet in-order - muc 4, dong 2 cua de cuong.
// Day la khung suon - logic chen/xoa de lai TODO cho Tuan 3.
template <typename Key, typename Value>
class BSTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertNode(Node* node, const Key& key, const Value& value);
    void inOrderTraverse(Node* node, std::vector<std::pair<Key, Value>>& out) const;
    void destroy(Node* node);

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { destroy(root); }

    BSTree(const BSTree&) = delete;
    BSTree& operator=(const BSTree&) = delete;

    void insert(const Key& key, const Value& value);
    // Tra ve danh sach (key, value) theo thu tu tang dan cua Key (vd: tang dan theo ten sach).
    std::vector<std::pair<Key, Value>> inOrder() const;
};

template <typename Key, typename Value>
void BSTree<Key, Value>::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <typename Key, typename Value>
typename BSTree<Key, Value>::Node* BSTree<Key, Value>::insertNode(Node* node, const Key& key, const Value& value) {
    // TODO (Tuan 3): chen theo quy tac BST thuong (khong can bang lai).
    if (!node) return new Node(key, value);
    return node;
}

template <typename Key, typename Value>
void BSTree<Key, Value>::insert(const Key& key, const Value& value) {
    root = insertNode(root, key, value);
}

template <typename Key, typename Value>
void BSTree<Key, Value>::inOrderTraverse(Node* node, std::vector<std::pair<Key, Value>>& out) const {
    if (!node) return;
    inOrderTraverse(node->left, out);
    out.push_back(std::make_pair(node->key, node->value));
    inOrderTraverse(node->right, out);
}

template <typename Key, typename Value>
std::vector<std::pair<Key, Value>> BSTree<Key, Value>::inOrder() const {
    std::vector<std::pair<Key, Value>> result;
    inOrderTraverse(root, result);
    return result;
}

#endif // BSTREE_H
