#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

// Danh sach lien ket don tong quat.
// Ap dung: danh sach phieu muon (LinkedList<PhieuMuon>) - muc 4, dong 4 cua de cuong.
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int soPhanTu;

public:
    LinkedList() : head(nullptr), tail(nullptr), soPhanTu(0) {}
    ~LinkedList();

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void pushBack(const T& value);             // them phieu muon moi vao cuoi danh sach
    bool removeIf(bool (*predicate)(const T&)); // xoa phan tu dau tien thoa dieu kien (vd: theo maPhieu)
    std::vector<T> toVector() const;            // xuat ra vector de duyet/in/thong ke de hon
    int size() const { return soPhanTu; }
    bool empty() const { return head == nullptr; }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

template <typename T>
void LinkedList<T>::pushBack(const T& value) {
    // TODO (Tuan 5): cap nhat con tro head/tail va soPhanTu cho dung.
    Node* node = new Node(value);
    (void)node;
}

template <typename T>
bool LinkedList<T>::removeIf(bool (*predicate)(const T&)) {
    // TODO (Tuan 5): duyet danh sach, xoa node dau tien thoa predicate,
    // nho noi lai con tro va cap nhat tail neu xoa phan tu cuoi.
    (void)predicate;
    return false;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const {
    std::vector<T> result;
    Node* cur = head;
    while (cur) {
        result.push_back(cur->data);
        cur = cur->next;
    }
    return result;
}

#endif // LINKEDLIST_H
