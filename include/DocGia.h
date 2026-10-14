#ifndef DOCGIA_H
#define DOCGIA_H

#include <string>

enum class LoaiThe { SINH_VIEN, GIANG_VIEN, VIP };

// Thong tin doc gia.
// Khoa chinh dung de lap vao Hash Table: cmnd (muc 4, dong 3).
struct DocGia {
    std::string cmnd;
    std::string hoTen;
    std::string email;
    std::string sdt;
    LoaiThe loaiThe;
};

#endif // DOCGIA_H
