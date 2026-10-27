#ifndef PHIEUMUON_H
#define PHIEUMUON_H
#include <string>
enum class TrangThaiMuon { DANG_MUON, DA_TRA, QUA_HAN };
struct PhieuMuon {
    std::string maPhieu;
    std::string cmndDocGia;
    std::string isbnSach;
    std::string ngayMuon;    
    std::string ngayHenTra; 
    std::string ngayTra;     
    TrangThaiMuon trangThai;
    double tienPhat;
};
