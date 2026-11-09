#include "DynamicArray.h"
#include <iostream>
using namespace std;
void khoiTaoMang(MangDong &md) {
    md.duLieu = NULL;
    md.soLuong = 0;
    md.sucChua = 0;
}
void themVaoCuoiMang(MangDong &md, GiaoDich gd) {
}
void inMang(MangDong md) {
    for (int i = 0; i < md.soLuong; i++) {
        cout << md.duLieu[i].maPhieu << " - " << md.duLieu[i].loaiGiaoDich << " - " << md.duLieu[i].ngayThucHien << endl;
    }
}
void giaiPhongMang(MangDong &md) {
    delete[] md.duLieu;
    md.duLieu = NULL;
    md.soLuong = 0;
    md.sucChua = 0;
}
