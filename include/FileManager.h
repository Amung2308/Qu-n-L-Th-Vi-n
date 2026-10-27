#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
#include "Sach.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include "GiaoDich.h"
namespace FileManager {
    bool docDanhSachSach(const std::string& duongDan, std::vector<Sach>& out);
    bool ghiDanhSachSach(const std::string& duongDan, const std::vector<Sach>& data);
    bool docDanhSachDocGia(const std::string& duongDan, std::vector<DocGia>& out);
    bool ghiDanhSachDocGia(const std::string& duongDan, const std::vector<DocGia>& data);
    bool docDanhSachPhieuMuon(const std::string& duongDan, std::vector<PhieuMuon>& out);
    bool ghiDanhSachPhieuMuon(const std::string& duongDan, const std::vector<PhieuMuon>& data);
    bool xuatBaoCaoVanBan(const std::string& duongDan, const std::string& noiDung);
    bool xuatDanhMucSachCSV(const std::string& duongDan, const std::vector<Sach>& data);
    bool saoLuuTheoNgay(const std::string& thuMucData, const std::string& ngayHienTai);
}
