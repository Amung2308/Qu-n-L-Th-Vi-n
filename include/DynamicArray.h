#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "GiaoDich.h"

struct MangDong {
    GiaoDich* duLieu;
    int soLuong;
    int sucChua;
};

void khoiTaoMang(MangDong &md);
void themVaoCuoiMang(MangDong &md, GiaoDich gd);
void inMang(MangDong md);
void giaiPhongMang(MangDong &md);

#endif
