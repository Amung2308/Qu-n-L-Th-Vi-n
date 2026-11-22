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
	int i1 = timChiSoDinh(dt, dinh1);
	int i2 = timChiSoDinh(dt, dinh2);
    if(i1==-1|| i2 == -1) 
        return;
    bool daCo = false;
    for (int k = 0; k < dt.soKe[i1]; k++) {
        if (dt.ke[i1][k] == i2) 
            daCo = true;
            break;
    }
    if (daCo)
        return;
	dt.ke[i1][dt.soKe[i1]] = i2;
	dt.soKe[i1]++;
	dt.ke[i2][dt.soKe[i2]] = i1;
	dt.soKe[i2]++;
}
void bfsDoThi(DoThi dt, string dinhBatDau) {
	int start = timChiSoDinh(dt, dinhBatDau);
    if (start == -1) {
        cout << "\nKhong tim thay sach nay trong do thi.";
        return;
    }
    bool daTham[SO_DINH_TOI_DA];
	for (int i=0; i < dt.soDinh; i++) 
        daTham[i] = false;
    int hangDoi[SO_DINH_TOI_DA];
    int dau = 0, cuoi = 0;
    hangDoi[cuoi++] = start;
    cuoi++;
	daTham[start] = true;
	cout << "\nGoi y sach cung loai: ";
    bool coKetQua = false;
    while (dau<cuoi)
    {
		int hienTai = hangDoi[dau];
        dau++;
        if (hienTai != start) {
            cout << "ISBN" << dt.tenDinh[hienTai] << "\n";
			coKetQua = true;
        }
        for (int k = 0; k < dt.soKe[hienTai]; k++) {
			int ke = dt.ke[hienTai][k];
            if (!daTham[ke]) {
				daTham[ke] = true;
                hangDoi[cuoi] = ke;
                cuoi++;
            }
        }
    }
    if (!coKetQua)
        cout << "\nKhong co sach nao cung the loai";
}

void dfsThamLai(DoThi dt, int dinh,int start, bool daTham[]) {
    daTham[dinh] = true;
    if (dinh != start) {
        cout << "ISBN" << dt.tenDinh[dinh] << "\n";
    }
    for (int k = 0; k < dt.soKe[dinh]; k++) {
        int ke = dt.ke[dinh][k];
        if (!daTham[ke]) {
            dfsThamLai(dt, ke, start, daTham);
        }
    }
}
void dfsDoThi(DoThi dt, string dinhBatDau) {
	int start = timChiSoDinh(dt, dinhBatDau);
    if (start == -1) {
		cout << "\nKhong tim thay sach nay trong do thi.";
        return;
    }
	bool daTham[SO_DINH_TOI_DA];
    for(int i=0; i<dt.soDinh; i++) 
		daTham[i] = false;
	cout << "\nGoi y sach cung loai: ";
	dfsThamLai(dt, start, start, daTham);
}
