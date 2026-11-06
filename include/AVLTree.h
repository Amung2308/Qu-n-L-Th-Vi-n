#ifndef AVLTREE_H
#define AVLTREE_H
#include "Sach.h"

struct NutAVL {
    Sach thongTin;
    NutAVL* trai;
    NutAVL* phai;
    int chieuCao;
};

NutAVL* taoNutAVL(Sach s);
int chieuCaoAVL(NutAVL* nut);
int canBangAVL(NutAVL* nut);
NutAVL* xoayTraiAVL(NutAVL* nut);
NutAVL* xoayPhaiAVL(NutAVL* nut);
NutAVL* themAVL(NutAVL* goc, Sach s);
NutAVL* xoaAVL(NutAVL* goc, string isbn);
NutAVL* timAVL(NutAVL* goc, string isbn);
void inThuTuAVL(NutAVL* goc);
void giaiPhongAVL(NutAVL* goc);

#endif