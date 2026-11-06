#ifndef BSTREE_H
#define BSTREE_H
#include "Sach.h"

struct NutBST {
    Sach thongTin;
    NutBST* trai;
    NutBST* phai;
};

NutBST* taoNutBST(Sach s);
NutBST* themBST(NutBST* goc, Sach s);
void inThuTuBST(NutBST* goc);
void giaiPhongBST(NutBST* goc);

#endif
