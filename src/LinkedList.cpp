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
    // TODO (Tuan 5): tao node moi, noi vao cuoi danh sach (dung con tro tail de
    // them O(1)), cap nhat head neu danh sach dang rong, tang soPhanTu.
    Node* node = new Node(phieu);
    (void)node;
}

PhieuMuon* LinkedList::timTheoMaPhieu(const std::string& maPhieu) {
    // TODO (Tuan 5-6): duyet danh sach tu head, so sanh cur->data.maPhieu voi
    // maPhieu, tra ve &(cur->data) neu trung, tra ve nullptr neu duyet het khong thay.
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
