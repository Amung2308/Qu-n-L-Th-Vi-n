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
    return node;
}

AVLTree::Node* AVLTree::rotateRight(Node* node) {
    return node;
}

AVLTree::Node* AVLTree::insertNode(Node* node, const Sach& sach) {
    if (!node) return new Node(sach);
    return node;
}

AVLTree::Node* AVLTree::findMinNode(Node* node) const {
    while (node && node->left) node = node->left;
    return node;
}

AVLTree::Node* AVLTree::removeNode(Node* node, const std::string& isbn) {
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
