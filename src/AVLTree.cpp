#include "AVLTree.h"

void AVLTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int AVLTree::getHeight(Node* node) const {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(Node* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLTree::Node* AVLTree::rotateLeft(Node* node) {
    // TODO (Tuan 3): xoay trai quanh 'node', cap nhat lai height cua cac node
    // lien quan, tra ve goc moi cua cum sau khi xoay.
    return node;
}

AVLTree::Node* AVLTree::rotateRight(Node* node) {
    // TODO (Tuan 3): xoay phai quanh 'node', cap nhat lai height, tra ve goc moi.
    return node;
}

AVLTree::Node* AVLTree::insertNode(Node* node, const Sach& sach) {
    // TODO (Tuan 3):
    // 1) Chen nhu BST binh thuong: so sanh sach.isbn voi node->data.isbn,
    //    de quy trai/phai.
    // 2) Cap nhat lai height cua node hien tai.
    // 3) Tinh balance factor, xu ly 4 truong hop mat can bang (LL, RR, LR, RL)
    //    bang rotateLeft/rotateRight.
    if (!node) return new Node(sach);
    return node;
}

AVLTree::Node* AVLTree::findMinNode(Node* node) const {
    while (node && node->left) node = node->left;
    return node;
}

AVLTree::Node* AVLTree::removeNode(Node* node, const std::string& isbn) {
    // TODO (Tuan 3): xoa nhu BST (3 truong hop: la / 1 con / 2 con - dung
    // findMinNode de lay successor), roi can bang lai AVL tu duoi len.
    (void)isbn;
    return node;
}

void AVLTree::insert(const Sach& sach) {
    root = insertNode(root, sach);
}

void AVLTree::remove(const std::string& isbn) {
    root = removeNode(root, isbn);
}

bool AVLTree::search(const std::string& isbn, Sach& outSach) const {
    // TODO (Tuan 3): tim kiem nhi phan theo isbn, gan vao outSach,
    // tra ve true neu thay, false neu khong.
    (void)isbn;
    (void)outSach;
    return false;
}

void AVLTree::inOrderTraverse(Node* node, std::vector<Sach>& out) const {
    if (!node) return;
    inOrderTraverse(node->left, out);
    out.push_back(node->data);
    inOrderTraverse(node->right, out);
}

std::vector<Sach> AVLTree::inOrder() const {
    std::vector<Sach> result;
    inOrderTraverse(root, result);
    return result;
}

int AVLTree::size() const {
    return (int)inOrder().size();
}
