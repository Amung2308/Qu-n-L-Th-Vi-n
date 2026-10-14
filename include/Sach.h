#ifndef SACH_H
#define SACH_H

#include <string>

// Thong tin mot dau sach trong thu vien.
// Khoa chinh dung de lap vao AVL Tree: isbn (muc 4, dong 1).
struct Sach {
    std::string isbn;
    std::string tenSach;
    std::string tacGia;
    std::string theLoai;   // dung lam dinh trong Graph goi y sach cung the loai (muc 3.5)
    int namXuatBan;
    int soLuong;            // so ban con lai co the cho muon
};

#endif // SACH_H
