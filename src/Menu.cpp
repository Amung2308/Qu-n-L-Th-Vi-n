#include "Menu.h"
#include <iostream>
using namespace std;

namespace Menu {

int hienThiMenuChinh() {
    cout << "\n========================================\n";
    cout << "      HE THONG QUAN LY THU VIEN\n";
    cout << "========================================\n";
    cout << "1. Quan ly Sach            (AVL Tree / BST)\n";
    cout << "2. Quan ly Doc gia         (Hash Table)\n";
    cout << "3. Muon - Tra sach         (Linked List)\n";
    cout << "4. Thong ke - Bao cao      (Dynamic Array)\n";
    cout << "5. Goi y - Tim kiem nang cao (Graph + Trie)\n";
    cout << "0. Thoat\n";
    cout << "========================================\n";
    cout << "Chon chuc nang: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuQuanLySach() {
    cout << "\n-- QUAN LY SACH --\n";
    cout << "1. Them sach\n2. Xoa sach\n3. Sua sach\n4. Tim theo ISBN\n";
    cout << "5. In danh muc theo ISBN (AVL)\n6. In danh muc theo ten (BST, in-order)\n";
    cout << "7. Tim theo tien to ten (Trie)\n0. Quay lai\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuQuanLyDocGia() {
    cout << "\n-- QUAN LY DOC GIA --\n";
    cout << "1. Them doc gia\n2. Xoa doc gia\n3. Sua doc gia\n4. Tim theo CMND\n";
    cout << "5. Thong ke theo loai the\n0. Quay lai\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuMuonTra() {
    cout << "\n-- MUON - TRA SACH --\n";
    cout << "1. Lap phieu muon\n2. Tra sach\n3. Xem phieu dang muon\n0. Quay lai\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuThongKe() {
    cout << "\n-- THONG KE - BAO CAO --\n";
    cout << "1. Luot muon theo thang/the loai/doc gia\n2. Top 10 sach muon nhieu nhat\n";
    cout << "3. Top 10 doc gia muon nhieu nhat\n4. Xuat bao cao ra file\n0. Quay lai\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuGoiYTimKiem() {
    cout << "\n-- GOI Y - TIM KIEM NANG CAO --\n";
    cout << "1. Goi y sach cung the loai (BFS/DFS)\n2. Autocomplete ten sach (Trie)\n";
    cout << "0. Quay lai\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

} // namespace Menu
