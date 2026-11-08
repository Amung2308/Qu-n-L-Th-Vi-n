#include "LinkedList.h"
#include <iostream>
using namespace std;
NutPhieu* taoNutPhieu(PhieuMuon p) {
    NutPhieu* nut = new NutPhieu;
    nut->thongTin = p;
    nut->tiep = NULL;
    return nut;
}
void themCuoiPhieu(NutPhieu* &dau, NutPhieu* &cuoi, PhieuMuon p) {
}
PhieuMuon* timTheoMaPhieu(NutPhieu* dau, string maPhieu) {
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
