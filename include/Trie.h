#ifndef TRIE_H
#define TRIE_H
#include <string>
using namespace std;

struct NutTrie {
    NutTrie* con[128];
    bool ketThuc;
};

NutTrie* taoNutTrie();
void themTrie(NutTrie* goc, string tenSach);
bool timTrie(NutTrie* goc, string tenSach);
void goiYTrie(NutTrie* goc, string tienTo);
void giaiPhongTrie(NutTrie* goc);

#endif
