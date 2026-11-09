#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "DocGia.h"

const int SO_BUCKET = 101;

struct NutBam {
    DocGia thongTin;
    NutBam* tiep;
};

void khoiTaoBam(NutBam* bang[]);
int bam(string cmnd);
void themBam(NutBam* bang[], DocGia dg);
bool timBam(NutBam* bang[], string cmnd, DocGia &ketQua);
bool xoaBam(NutBam* bang[], string cmnd);
void giaiPhongBam(NutBam* bang[]);

#endif
