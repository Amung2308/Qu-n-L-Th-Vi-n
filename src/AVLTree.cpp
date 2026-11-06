#include "AVLTree.h"
#include <iostream>
using namespace std;
NutAVL* taoNutAVL(Sach s) {
    NutAVL* nut = new NutAVL;
    nut->thongTin = s;
    nut->trai = NULL;
    nut->phai = NULL;
    nut->chieuCao = 1;
    return nut;
}
int chieuCaoAVL(NutAVL* nut) {
    if (nut == NULL) return 0;
    return nut->chieuCao;
}
int canBangAVL(NutAVL* nut) {
    if (nut == NULL) return 0;
    return chieuCaoAVL(nut->trai) - chieuCaoAVL(nut->phai);
}
NutAVL* xoayPhaiAVL(NutAVL* nut) {
    NutAVL* traiCuaNut = nut->trai;
    nut->trai = traiCuaNut->phai;
    traiCuaNut->phai = nut;

    int tr1 = chieuCaoAVL(nut->trai);
    int ph1 = chieuCaoAVL(nut->phai);
    nut->chieuCao = 1 + (tr1 > ph1 ? tr1 : ph1);

    int tr2 = chieuCaoAVL(traiCuaNut->trai);
    int ph2 = chieuCaoAVL(traiCuaNut->phai);
    traiCuaNut->chieuCao = 1 + (tr2 > ph2 ? tr2 : ph2);

    return traiCuaNut;
}

NutAVL* xoayTraiAVL(NutAVL* nut) {
    NutAVL* phaiCuaNut = nut->phai;
    nut->phai = phaiCuaNut->trai;
    phaiCuaNut->trai = nut;

    int tr1 = chieuCaoAVL(nut->trai);
    int ph1 = chieuCaoAVL(nut->phai);
    nut->chieuCao = 1 + (tr1 > ph1 ? tr1 : ph1);

    int tr2 = chieuCaoAVL(phaiCuaNut->trai);
    int ph2 = chieuCaoAVL(phaiCuaNut->phai);
    phaiCuaNut->chieuCao = 1 + (tr2 > ph2 ? tr2 : ph2);

    return phaiCuaNut;
}
NutAVL* themAVL(NutAVL* goc, Sach s) {
    if (goc == NULL) return taoNutAVL(s);
        if (s.isbn < goc->thongTin.isbn) {
        goc->trai = themAVL(goc->trai, s);
        }
        else if (s.isbn > goc->thongTin.isbn) {
        goc->phai = themAVL(goc->phai, s);
        }
        else {
        return goc;
        }
    int trai = chieuCaoAVL(goc->trai);
    int phai = chieuCaoAVL(goc->phai);
    goc->chieuCao = 1 + (trai > phai ? trai : phai);
    int canBang = canBangAVL(goc);
    if (canBang > 1 && s.isbn < goc->trai->thongTin.isbn) {
        return xoayPhaiAVL(goc);
    }
    if (canBang < -1 && s.isbn > goc->phai->thongTin.isbn) {
        return xoayTraiAVL(goc);
    }
    if (canBang > 1 && s.isbn > goc->trai->thongTin.isbn) {
        goc->trai = xoayTraiAVL(goc->trai);
        return xoayPhaiAVL(goc);
    }
    if (canBang < -1 && s.isbn < goc->phai->thongTin.isbn) {
        goc->phai = xoayPhaiAVL(goc->phai);
        return xoayTraiAVL(goc);
    }
    return goc;
}
NutAVL* xoaAVL(NutAVL* goc, string isbn) {
	if (goc == NULL)
        return goc;
    if (isbn == goc->thongTin.isbn)
        return NULL;
    if(isbn<goc->thongTin.isbn)
		return timAVL(goc->trai, isbn); 
	return timAVL(goc->phai, isbn);
}
NutAVL* timAVL(NutAVL* goc, string isbn) {
    return NULL;
}
void inThuTuAVL(NutAVL* goc) {
    if (goc == NULL) 
        return;
    inThuTuAVL(goc->trai);
    cout << goc->thongTin.isbn << " - " << goc->thongTin.tenSach << endl;
    inThuTuAVL(goc->phai);
}
void giaiPhongAVL(NutAVL* goc) {
    if (goc == NULL) return;
    giaiPhongAVL(goc->trai);
    giaiPhongAVL(goc->phai);
    delete goc;
}
