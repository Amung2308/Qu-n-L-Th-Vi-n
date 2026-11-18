#include "LinkedList.h"
#include <iostream>
using namespace std;
NutPhieu* taoNutPhieu(PhieuMuon p) {
    NutPhieu* nut = new NutPhieu;
    nut->thongTin = p;
    nut->tiep = NULL;
    return nut;
}
void themCuoiPhieu(NutPhieu*& dau, NutPhieu*& cuoi, PhieuMuon p) {
    NutPhieu* nut = taoNutPhieu(p);
    if (dau == NULL) {
        dau = nut;
        cuoi = nut;
    }
    else {
        cuoi->tiep = nut;
        cuoi = nut;
    }
}

PhieuMuon* timTheoMaPhieu(NutPhieu* dau, string maPhieu) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        if (cur->thongTin.maPhieu == maPhieu) return &(cur->thongTin);
        cur = cur->tiep;
    }
    return NULL;
}
void inDanhSachPhieu(NutPhieu* dau) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        cout << cur->thongTin.maPhieu << " - " << cur->thongTin.isbnSach << endl;
        cur = cur->tiep;
    }
}
void giaiPhongDanhSachPhieu(NutPhieu* dau) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        NutPhieu* tiep = cur->tiep;
        delete cur;
        cur = tiep;
    }
}
