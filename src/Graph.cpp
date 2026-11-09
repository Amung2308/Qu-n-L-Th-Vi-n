#include "Graph.h"
#include <iostream>
using namespace std;
void khoiTaoDoThi(DoThi &dt) {
    dt.soDinh = 0;
    for (int i = 0; i < SO_DINH_TOI_DA; i++) dt.soKe[i] = 0;
}
int timChiSoDinh(DoThi dt, string ten) {
    for (int i = 0; i < dt.soDinh; i++) {
        if (dt.tenDinh[i] == ten) return i;
    }
    return -1;
}
void themDinh(DoThi &dt, string ten) {
    if (timChiSoDinh(dt, ten) != -1) return;
    dt.tenDinh[dt.soDinh] = ten;
    dt.soDinh++;
}
void themCanh(DoThi &dt, string dinh1, string dinh2) {

}
void bfsDoThi(DoThi dt, string dinhBatDau) {

}
void dfsDoThi(DoThi dt, string dinhBatDau) {

}
