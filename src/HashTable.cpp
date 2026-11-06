#include "HashTable.h"
void khoiTaoBam(NutBam* bang[]) {
    for (int i = 0; i < SO_BUCKET; i++) bang[i] = NULL;
}
int bam(string cmnd) {
    return 0;
}
void themBam(NutBam* bang[], DocGia dg) {
}
bool timBam(NutBam* bang[], string cmnd, DocGia &ketQua) {
    return false;
}
bool xoaBam(NutBam* bang[], string cmnd) {
    return false;
}
void giaiPhongBam(NutBam* bang[]) {
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
