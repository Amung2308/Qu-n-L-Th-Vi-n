#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <vector>
#include "PhieuMuon.h"

// Danh sach lien ket don - quan ly phieu muon (muc 4, dong 4 cua de cuong).
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
    ~LinkedList();

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void pushBack(const PhieuMuon& phieu); // them phieu muon moi vao cuoi danh sach

    // Tra ve con tro toi phieu co maPhieu trung (de sua truc tiep, vd luc tra sach
    // can cap nhat trangThai/ngayTra/tienPhat), hoac nullptr neu khong tim thay.
    PhieuMuon* timTheoMaPhieu(const std::string& maPhieu);

    std::vector<PhieuMuon> toVector() const; // xuat ra vector de duyet/in/thong ke
    int size() const { return soPhanTu; }
    bool empty() const { return head == nullptr; }
};

#endif // LINKEDLIST_H
