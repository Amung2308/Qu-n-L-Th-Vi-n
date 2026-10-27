#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <vector>
#include "PhieuMuon.h"
class LinkedList {
private:
    struct Node {
        PhieuMuon data;
        Node* next;
        Node(const PhieuMuon& p) : data(p), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int soPhanTu;
public:
    LinkedList() : head(nullptr), tail(nullptr), soPhanTu(0) {}
    LinkedList();
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    void pushBack(const PhieuMuon& phieu); 
    PhieuMuon* timTheoMaPhieu(const std::string& maPhieu);
    std::vector<PhieuMuon> toVector() const;
    int size() const { return soPhanTu; }
    bool empty() const { return head == nullptr; }
};
