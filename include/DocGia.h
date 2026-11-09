#ifndef DOCGIA_H
#define DOCGIA_H
#include <string>
using namespace std;

enum LoaiThe { SINH_VIEN, GIANG_VIEN, VIP };

struct DocGia {
    string cmnd;
    string hoTen;
    string email;
    string sdt;
    LoaiThe loaiThe;
};

#endif
