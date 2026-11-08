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
void inDanhSachPhieu(NutPhieu* dau);
void giaiPhongDanhSachPhieu(NutPhieu* dau);

#endif
