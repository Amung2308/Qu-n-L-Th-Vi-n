#include "FileManager.h"
#include <fstream>

namespace FileManager {

bool docDanhSachSach(const std::string& duongDan, std::vector<Sach>& out) {
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachSach(const std::string& duongDan, const std::vector<Sach>& data) {
    (void)duongDan;
    (void)data;
    return false;
}

bool docDanhSachDocGia(const std::string& duongDan, std::vector<DocGia>& out) {
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachDocGia(const std::string& duongDan, const std::vector<DocGia>& data) {
    (void)duongDan;
    (void)data;
    return false;
}

bool docDanhSachPhieuMuon(const std::string& duongDan, std::vector<PhieuMuon>& out) {
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachPhieuMuon(const std::string& duongDan, const std::vector<PhieuMuon>& data) {
    (void)duongDan;
    (void)data;
    return false;
}

bool xuatBaoCaoVanBan(const std::string& duongDan, const std::string& noiDung) {
    std::ofstream f(duongDan);
    if (!f.is_open()) return false;
    f << noiDung;
    return true;
}

bool xuatDanhMucSachCSV(const std::string& duongDan, const std::vector<Sach>& data) {
    (void)duongDan;
    (void)data;
    return false;
}

bool saoLuuTheoNgay(const std::string& thuMucData, const std::string& ngayHienTai) {
    (void)thuMucData;
    (void)ngayHienTai;
    return false;
}

} 
