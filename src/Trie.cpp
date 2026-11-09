#include "Trie.h"
NutTrie* taoNutTrie() {
    NutTrie* nut = new NutTrie;
    for (int i = 0; i < 128; i++) nut->con[i] = NULL;
    nut->ketThuc = false;
    return nut;
}
void themTrie(NutTrie* goc, string tenSach) {
}
bool timTrie(NutTrie* goc, string tenSach) {
    return false;
}
void goiYTrie(NutTrie* goc, string tienTo) {
}
void giaiPhongTrie(NutTrie* goc) {
    if (goc == NULL) return;
    for (int i = 0; i < 128; i++) giaiPhongTrie(goc->con[i]);
    delete goc;
}