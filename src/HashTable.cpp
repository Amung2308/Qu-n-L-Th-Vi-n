#include "HashTable.h"
void khoiTaoBam(NutBam* bang[]) {
    for (int i = 0; i < SO_BUCKET; i++) bang[i] = NULL;
}
int bam(string cmnd) {
    int tong = 0;
    for (int i = 0; i < (int)cmnd.length(); i++) {
        tong = tong * 31 + cmnd[i];
    }
    if (tong < 0) tong = -tong;
    return tong % SO_BUCKET;
}

void themBam(NutBam* bang[], DocGia dg) {
    int chiSo = bam(dg.cmnd);
    NutBam* cur = bang[chiSo];
    while (cur != NULL) {
        if (cur->thongTin.cmnd == dg.cmnd) { cur->thongTin = dg; return; }
        cur = cur->tiep;
    }
    NutBam* nut = new NutBam;
    nut->thongTin = dg;
    nut->tiep = bang[chiSo];
    bang[chiSo] = nut;
}

bool timBam(NutBam* bang[], string cmnd, DocGia& ketQua) {
    int chiSo = bam(cmnd);
    NutBam* cur = bang[chiSo];
    while (cur != NULL) {
        if (cur->thongTin.cmnd == cmnd) { ketQua = cur->thongTin; return true; }
        cur = cur->tiep;
    }
    return false;
}

bool xoaBam(NutBam* bang[], string cmnd) {
    int chiSo = bam(cmnd);
    NutBam* cur = bang[chiSo];
    NutBam* truoc = NULL;
    while (cur != NULL) {
        if (cur->thongTin.cmnd == cmnd) {
            if (truoc == NULL) bang[chiSo] = cur->tiep;
            else truoc->tiep = cur->tiep;
            delete cur;
            return true;
        }
        truoc = cur;
        cur = cur->tiep;
    }
    return false;
}void giaiPhongBam(NutBam* bang[]) {
    for (int i = 0; i < SO_BUCKET; i++) {
        NutBam* cur = bang[i];
        while (cur != NULL) {
            NutBam* tiep = cur->tiep;
            delete cur;
            cur = tiep;
        }
        bang[i] = NULL;
    }
}
