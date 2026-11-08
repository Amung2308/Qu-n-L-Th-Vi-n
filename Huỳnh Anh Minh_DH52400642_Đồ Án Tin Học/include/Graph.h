#ifndef GRAPH_H
#define GRAPH_H
#include <string>
using namespace std;

const int SO_DINH_TOI_DA = 50;
const int SO_KE_TOI_DA = 50;

struct DoThi {
    string tenDinh[SO_DINH_TOI_DA];
    int soDinh;
    int ke[SO_DINH_TOI_DA][SO_KE_TOI_DA];
    int soKe[SO_DINH_TOI_DA];
};

void khoiTaoDoThi(DoThi &dt);
int timChiSoDinh(DoThi dt, string ten);
void themDinh(DoThi &dt, string ten);
void themCanh(DoThi &dt, string dinh1, string dinh2);
void bfsDoThi(DoThi dt, string dinhBatDau);
void dfsDoThi(DoThi dt, string dinhBatDau);

#endif
