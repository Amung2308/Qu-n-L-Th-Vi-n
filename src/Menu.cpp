#include "Menu.h"
#include <iostream>
using namespace std;
int hienThiMenuChinh() {
    cout << "\n========================================\n";
    cout << "      HE THONG QUAN LY THU VIEN\n";
    cout << "========================================\n";
    cout << "\n1. Quan ly Sach";
    cout << "\n2. Quan ly Doc gia";
    cout << "\n3. Muon - Tra sach";
    cout << "\n4. Thong ke - Bao cao";
    cout << "\n5. Goi y - Tim kiem nang cao";
    cout << "\n0. Thoat";
    cout << "\n========================================\n";
    cout << "Chon chuc nang: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}
int hienThiMenuQuanLySach() {
    cout << "\n-- QUAN LY SACH --\n";
    cout << "\n1. Them sach";
    cout << "\n2. Xoa sach";
    cout << "\n3. Sua sach";
    cout << "\n4. Tim theo ISBN";
    cout << "\n5. In danh muc theo ISBN (AVL)";
    cout << "\n6. In danh muc theo ten (BST)";
    cout << "\n7. Tim theo tien to ten (Trie)";
    cout << "\n0. Quay lai";
    cout << "\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuQuanLyDocGia() {
    cout << "\n-- QUAN LY DOC GIA --\n";
    cout << "\n1. Them doc gia";
    cout << "\n2. Xoa doc gia";
    cout << "\n3. Sua doc gia";
    cout << "\n4. Tim theo CMND";
    cout << "\n5. Thong ke theo loai the";
    cout << "\n0. Quay lai";
    cout << "\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuMuonTra() {
    cout << "\n-- MUON - TRA SACH --\n";
    cout << "\n1. Lap phieu muon";
    cout << "\n2. Tra sach";
    cout << "\n3. Xem phieu dang muon";
    cout << "\n0. Quay lai";
    cout << "\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuThongKe() {
    cout << "\n-- THONG KE - BAO CAO --\n";
    cout << "\n1. Luot muon theo thang/the loai/doc gia";
    cout << "\n2. Top 10 sach muon nhieu nhat";
    cout << "\n3. Top 10 doc gia muon nhieu nhat";
    cout << "\n4. Xuat bao cao ra file";
    cout << "\n0. Quay lai";
    cout << "\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}

int hienThiMenuGoiYTimKiem() {
    cout << "\n-- GOI Y - TIM KIEM NANG CAO --\n";
    cout << "\n1. Goi y sach cung the loai (BFS/DFS)";
    cout << "\n2. Autocomplete ten sach (Trie)";
    cout << "\n0. Quay lai";
    cout << "\nChon: ";
    int luaChon;
    cin >> luaChon;
    return luaChon;
}
