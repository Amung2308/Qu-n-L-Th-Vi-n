#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "PhieuMuon.h"

struct NutPhieu {
    PhieuMuon thongTin;
    NutPhieu* tiep;
};

NutPhieu* taoNutPhieu(PhieuMuon p);
void themCuoiPhieu(NutPhieu* &dau, NutPhieu* &cuoi, PhieuMuon p);
PhieuMuon* timTheoMaPhieu(NutPhieu* dau, string maPhieu);
int demPhieuDangMuon(NutPhieu* dau,string cmnd);
void inPhieuDangMuon(NutPhieu* dau, string cmnd);
void thongKeTop10SachMuonNhieuNhat(NutPhieu* dau);
void thonKeTop10DocGiaMuonNhieuNhat(NutPhieu* dau);
void inDanhSachPhieu(NutPhieu* dau);
void giaiPhongDanhSachPhieu(NutPhieu* dau);


#endif
