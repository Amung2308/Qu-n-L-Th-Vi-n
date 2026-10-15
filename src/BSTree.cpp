#include "BSTree.h"

void BSTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

BSTree::Node* BSTree::insertNode(Node* node, const Sach& sach) {
    // TODO (Tuan 3): chen theo quy tac BST thuong (khong can bang lai),
    // so sanh theo sach.tenSach.
    if (!node) return new Node(sach);
    return node;
}

void BSTree::insert(const Sach& sach) {
    root = insertNode(root, sach);
}

void BSTree::inOrderTraverse(Node* node, std::vector<Sach>& out) const {
    if (!node) return;
    inOrderTraverse(node->left, out);
    out.push_back(node->data);
    inOrderTraverse(node->right, out);
}

std::vector<Sach> BSTree::inOrder() const {
    std::vector<Sach> result;
    inOrderTraverse(root, result);
    return result;
}
