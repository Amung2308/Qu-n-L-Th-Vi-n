#ifndef DOCGIA_H
#define DOCGIA_H
#include <string>
enum class LoaiThe { SINH_VIEN, GIANG_VIEN, VIP };
struct DocGia {
    std::string cmnd;
    std::string hoTen;
    std::string email;
    std::string sdt;
    LoaiThe loaiThe;
};
