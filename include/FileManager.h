#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Sach.h"
#include "DocGia.h"
#include "PhieuMuon.h"

bool docDanhSachSach(string duongDan, Sach ds[], int &soLuong, int soLuongToiDa);
bool ghiDanhSachSach(string duongDan, Sach ds[], int soLuong);
bool docDanhSachDocGia(string duongDan, DocGia ds[], int &soLuong, int soLuongToiDa);
bool ghiDanhSachDocGia(string duongDan, DocGia ds[], int soLuong);
bool docDanhSachPhieu(string duongDan, PhieuMuon ds[], int &soLuong, int soLuongToiDa);
bool ghiDanhSachPhieu(string duongDan, PhieuMuon ds[], int soLuong);
bool xuatBaoCaoVanBan(string duongDan, string noiDung);
bool xuatDanhMucSachCSV(string duongDan, Sach ds[], int soLuong);
bool saoLuuTheoNgay(string thuMucData, string ngayHienTai);

#endif
