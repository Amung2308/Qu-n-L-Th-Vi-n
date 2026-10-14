#ifndef MENU_H
#define MENU_H

// Cac ham hien thi menu (chi phan giao dien, khong chua logic xu ly du lieu -
// logic se goi den cac CTDL o Tuan 3 tro di). Tach rieng de main.cpp gon hon.
namespace Menu {
    int hienThiMenuChinh();        // tra ve lua chon cua nguoi dung (0-5)
    int hienThiMenuQuanLySach();
    int hienThiMenuQuanLyDocGia();
    int hienThiMenuMuonTra();
    int hienThiMenuThongKe();
    int hienThiMenuGoiYTimKiem();
}

#endif // MENU_H
