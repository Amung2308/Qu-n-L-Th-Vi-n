#ifndef PHIEUMUON_H
#define PHIEUMUON_H
#include <string>
using namespace std;

enum TrangThaiMuon { DANG_MUON, DA_TRA, QUA_HAN };

struct PhieuMuon {
    string maPhieu;
    string cmndDocGia;
    string isbnSach;
    string ngayMuon;
    string ngayHenTra;
    string ngayTra;
    TrangThaiMuon trangThai;
    double tienPhat;
};

#endif
