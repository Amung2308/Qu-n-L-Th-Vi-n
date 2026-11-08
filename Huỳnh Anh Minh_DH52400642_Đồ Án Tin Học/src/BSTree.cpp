#include "BSTree.h"
#include <iostream>
using namespace std;

NutBST* taoNutBST(Sach s) {
    NutBST* nut = new NutBST;
    nut->thongTin = s;
    nut->trai = NULL;
    nut->phai = NULL;
    return nut;
}

NutBST* themBST(NutBST* goc, Sach s) {
    if (goc == NULL) return taoNutBST(s);
    if (s.tenSach < goc->thongTin.tenSach) {
        goc->trai = themBST(goc->trai, s);
    }
    else {
        goc->phai = themBST(goc->phai, s);
    }
    return goc;
}

void inThuTuBST(NutBST* goc) {
    if (goc == NULL) return;
    inThuTuBST(goc->trai);
    cout << goc->thongTin.tenSach << " - " << goc->thongTin.isbn << endl;
    inThuTuBST(goc->phai);
}

void giaiPhongBST(NutBST* goc) {
    if (goc == NULL) return;
    giaiPhongBST(goc->trai);
    giaiPhongBST(goc->phai);
    delete goc;
}
