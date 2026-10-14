#include "FileManager.h"
#include <fstream>

namespace FileManager {

bool docDanhSachSach(const std::string& duongDan, std::vector<Sach>& out) {
    // TODO (Tuan 5): mo file nhi phan (ios::binary), doc so luong phan tu, roi doc tung
    // Sach. Luu y: std::string khong the ghi/doc truc tiep bang fwrite - can tu serialize
    // (vd: ghi do dai chuoi truoc, roi ghi noi dung chuoi; hoac dung std::ofstream << voi
    // dinh dang co do dai co dinh / ky tu phan cach).
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachSach(const std::string& duongDan, const std::vector<Sach>& data) {
    // TODO (Tuan 5): mo file nhi phan de ghi, ghi so luong phan tu truoc, roi ghi tung Sach
    // theo dung thu tu da doc o docDanhSachSach() de hai ham khop nhau.
    (void)duongDan;
    (void)data;
    return false;
}

bool docDanhSachDocGia(const std::string& duongDan, std::vector<DocGia>& out) {
    // TODO (Tuan 5): tuong tu docDanhSachSach, nhung cho DocGia.
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachDocGia(const std::string& duongDan, const std::vector<DocGia>& data) {
    // TODO (Tuan 5): tuong tu ghiDanhSachSach, nhung cho DocGia.
    (void)duongDan;
    (void)data;
    return false;
}

bool docDanhSachPhieuMuon(const std::string& duongDan, std::vector<PhieuMuon>& out) {
    // TODO (Tuan 5): tuong tu, cho PhieuMuon.
    (void)duongDan;
    (void)out;
    return false;
}

bool ghiDanhSachPhieuMuon(const std::string& duongDan, const std::vector<PhieuMuon>& data) {
    // TODO (Tuan 5): tuong tu, cho PhieuMuon.
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
    // TODO (Tuan 6/9, chuc nang mo rong 3.7): ghi header CSV (isbn,tenSach,tacGia,theLoai,
    // namXuatBan,soLuong) roi moi dong la mot cuon sach, ngan cach bang dau phay.
    (void)duongDan;
    (void)data;
    return false;
}

bool saoLuuTheoNgay(const std::string& thuMucData, const std::string& ngayHienTai) {
    // TODO (Tuan 9): tao thu muc data/backup/<ngayHienTai>/ va sao chep cac file .dat vao do.
    (void)thuMucData;
    (void)ngayHienTai;
    return false;
}

} // namespace FileManager
