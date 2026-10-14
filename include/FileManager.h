#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Sach.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include "GiaoDich.h"

// Lop tien ich doc/ghi du lieu ra file - KHONG dung CSDL (dung quy dinh de cuong).
// Luu bang file nhi phan (.dat) cho du lieu chinh, file van ban (.txt) cho log/bao cao.
// Ap dung: muc 3.6 (luu tru) va muc 4, dong 7 (doc/ghi file nhi phan).
namespace FileManager {

    // --- File nhi phan (.dat) - doc/ghi toan bo du lieu khi khoi dong / thoat ---
    bool docDanhSachSach(const std::string& duongDan, std::vector<Sach>& out);
    bool ghiDanhSachSach(const std::string& duongDan, const std::vector<Sach>& data);

    bool docDanhSachDocGia(const std::string& duongDan, std::vector<DocGia>& out);
    bool ghiDanhSachDocGia(const std::string& duongDan, const std::vector<DocGia>& data);

    bool docDanhSachPhieuMuon(const std::string& duongDan, std::vector<PhieuMuon>& out);
    bool ghiDanhSachPhieuMuon(const std::string& duongDan, const std::vector<PhieuMuon>& data);

    // --- File van ban (.txt) - xuat bao cao / nhat ky, import/export danh muc sach ---
    bool xuatBaoCaoVanBan(const std::string& duongDan, const std::string& noiDung);
    bool xuatDanhMucSachCSV(const std::string& duongDan, const std::vector<Sach>& data);

    // Sao luu du lieu theo ngay - muc 3.6. Vd: copy data/*.dat sang data/backup/yyyy-mm-dd/.
    bool saoLuuTheoNgay(const std::string& thuMucData, const std::string& ngayHienTai);
}

#endif // FILEMANAGER_H
