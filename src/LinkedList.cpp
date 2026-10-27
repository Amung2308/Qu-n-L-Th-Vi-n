#include "LinkedList.h"

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void LinkedList::pushBack(const PhieuMuon& phieu) {
    Node* node = new Node(phieu);
    (void)node;
}

PhieuMuon* LinkedList::timTheoMaPhieu(const std::string& maPhieu) {
    (void)maPhieu;
    return nullptr;
}

std::vector<PhieuMuon> LinkedList::toVector() const {
    std::vector<PhieuMuon> result;
    Node* cur = head;
    while (cur) {
        result.push_back(cur->data);
        cur = cur->next;
    }
    return result;
}
