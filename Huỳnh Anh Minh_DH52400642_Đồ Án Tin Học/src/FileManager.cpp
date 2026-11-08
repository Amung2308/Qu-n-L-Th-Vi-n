#include "FileManager.h"
#include <fstream>
bool docDanhSachSach(string duongDan, Sach ds[], int &soLuong, int soLuongToiDa) {
    return false;
}
bool ghiDanhSachSach(string duongDan, Sach ds[], int soLuong) {
    return false;
}
bool docDanhSachDocGia(string duongDan, DocGia ds[], int &soLuong, int soLuongToiDa) {
    return false;
}
bool ghiDanhSachDocGia(string duongDan, DocGia ds[], int soLuong) {
    return false;
}
bool docDanhSachPhieu(string duongDan, PhieuMuon ds[], int &soLuong, int soLuongToiDa) {
    return false;
}
bool ghiDanhSachPhieu(string duongDan, PhieuMuon ds[], int soLuong) {
    return false;
}
bool xuatBaoCaoVanBan(string duongDan, string noiDung) {
    ofstream f(duongDan.c_str());
    if (!f.is_open()) return false;
    f << noiDung;
    return true;
}
bool xuatDanhMucSachCSV(string duongDan, Sach ds[], int soLuong) {
    return false;
}
bool saoLuuTheoNgay(string thuMucData, string ngayHienTai) {
    return false;
}
