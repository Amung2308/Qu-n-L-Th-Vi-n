#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <vector>
#include "Sach.h"

// Cay AVL - quan ly Sach theo ISBN (muc 4, dong 1 cua de cuong).
// Day la khung suon: cac ham thuat toan con lai la TODO, se cai dat o Tuan 3.
class AVLTree {
private:
    struct Node {
        Sach data;
        Node* left;
        Node* right;
        int height;

        Node(const Sach& s) : data(s), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) const;
    int getBalanceFactor(Node* node) const;
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* insertNode(Node* node, const Sach& sach);
    Node* removeNode(Node* node, const std::string& isbn);
    Node* findMinNode(Node* node) const;
    void inOrderTraverse(Node* node, std::vector<Sach>& out) const;
    void destroy(Node* node);

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { destroy(root); }

    // Khong cho sao chep ngam dinh (tranh double-free con tro).
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(const Sach& sach);
    void remove(const std::string& isbn);
    bool search(const std::string& isbn, Sach& outSach) const;
    std::vector<Sach> inOrder() const; // liet ke tang dan theo ISBN
    int size() const;
    bool empty() const { return root == nullptr; }
};

#endif // AVLTREE_H
