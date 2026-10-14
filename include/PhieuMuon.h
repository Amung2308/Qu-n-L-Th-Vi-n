#ifndef PHIEUMUON_H
#define PHIEUMUON_H

#include <string>

enum class TrangThaiMuon { DANG_MUON, DA_TRA, QUA_HAN };

// Mot phieu muon sach - phan tu cua Linked List quan ly phieu muon (muc 4, dong 4).
struct PhieuMuon {
    std::string maPhieu;
    std::string cmndDocGia;
    std::string isbnSach;
    std::string ngayMuon;    // dd/mm/yyyy
    std::string ngayHenTra;  // dd/mm/yyyy
    std::string ngayTra;     // rong neu chua tra
    TrangThaiMuon trangThai;
    double tienPhat;
};

#endif // PHIEUMUON_H
