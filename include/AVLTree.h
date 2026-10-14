#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <utility>

// Cay AVL tong quat (Key, Value).
// Ap dung: quan ly Sach theo ISBN - muc 4, dong 1 cua de cuong.
// Day la KHUNG SUON (skeleton): cac ham mang tinh thuat toan con lai la
// TODO, se cai dat o Tuan 3. Cay van bien dich va chay duoc o giai doan nay.
template <typename Key, typename Value>
class AVLTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        int height;

        Node(const Key& k, const Value& v)
            : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) const;
    int getBalanceFactor(Node* node) const;
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* insertNode(Node* node, const Key& key, const Value& value);
    Node* removeNode(Node* node, const Key& key);
    Node* findMinNode(Node* node) const;
    void inOrderTraverse(Node* node, std::vector<std::pair<Key, Value>>& out) const;
    void destroy(Node* node);

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { destroy(root); }

    // Khong cho sao chep ngam dinh (de tranh double-free con tro) - neu can,
    // tu cai dat copy constructor / operator= sau.
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(const Key& key, const Value& value);
    void remove(const Key& key);
    bool search(const Key& key, Value& outValue) const;
    std::vector<std::pair<Key, Value>> inOrder() const; // liet ke tang dan theo Key (ISBN)
    int size() const;
    bool empty() const { return root == nullptr; }
};

// ---------------- Trien khai (template nen phai nam trong header) ----------------

template <typename Key, typename Value>
void AVLTree<Key, Value>::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::getHeight(Node* node) const {
    return node ? node->height : 0;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::getBalanceFactor(Node* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateLeft(Node* node) {
    // TODO (Tuan 3): xoay trai quanh 'node', cap nhat lai height cua cac node lien quan,
    // tra ve goc moi cua cum sau khi xoay.
    return node;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateRight(Node* node) {
    // TODO (Tuan 3): xoay phai quanh 'node', cap nhat lai height, tra ve goc moi.
    return node;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::insertNode(Node* node, const Key& key, const Value& value) {
    // TODO (Tuan 3):
    // 1) Chen nhu BST binh thuong (so sanh key, de quy trai/phai).
    // 2) Cap nhat lai height cua node hien tai.
    // 3) Tinh balance factor, xu ly 4 truong hop mat can bang (LL, RR, LR, RL)
    //    bang rotateLeft/rotateRight.
    if (!node) return new Node(key, value);
    return node;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::findMinNode(Node* node) const {
    while (node && node->left) node = node->left;
    return node;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::removeNode(Node* node, const Key& key) {
    // TODO (Tuan 3): xoa nhu BST (3 truong hop: la / 1 con / 2 con - dung findMinNode
    // de lay successor), roi can bang lai AVL tu duoi len.
    return node;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::insert(const Key& key, const Value& value) {
    root = insertNode(root, key, value);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::remove(const Key& key) {
    root = removeNode(root, key);
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::search(const Key& key, Value& outValue) const {
    // TODO (Tuan 3): tim kiem nhi phan theo key, gan vao outValue va tra ve true neu thay.
    (void)key;
    (void)outValue;
    return false;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::inOrderTraverse(Node* node, std::vector<std::pair<Key, Value>>& out) const {
    if (!node) return;
    inOrderTraverse(node->left, out);
    out.push_back(std::make_pair(node->key, node->value));
    inOrderTraverse(node->right, out);
}

template <typename Key, typename Value>
std::vector<std::pair<Key, Value>> AVLTree<Key, Value>::inOrder() const {
    std::vector<std::pair<Key, Value>> result;
    inOrderTraverse(root, result);
    return result;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::size() const {
    return (int)inOrder().size();
}

#endif // AVLTREE_H
