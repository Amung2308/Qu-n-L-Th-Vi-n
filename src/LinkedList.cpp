#include "LinkedList.h"
#include <iostream>
using namespace std;
NutPhieu* taoNutPhieu(PhieuMuon p) {
    NutPhieu* nut = new NutPhieu;
    nut->thongTin = p;
    nut->tiep = NULL;
    return nut;
}
void themCuoiPhieu(NutPhieu*& dau, NutPhieu*& cuoi, PhieuMuon p) {
    NutPhieu* nut = taoNutPhieu(p);
    if (dau == NULL) {
        dau = nut;
        cuoi = nut;
    }
    else {
        cuoi->tiep = nut;
        cuoi = nut;
    }
}

PhieuMuon* timTheoMaPhieu(NutPhieu* dau, string maPhieu) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        if (cur->thongTin.maPhieu == maPhieu) return &(cur->thongTin);
        cur = cur->tiep;
    }
    return NULL;
}

int demPhieuDangMuon(NutPhieu* dau, string cmnd) {
    int dem = 0;
	NutPhieu* cur = dau;
    while (cur!=NULL)
    {
        if(cur->thongTin.cmndDocGia == cmnd && cur->thongTin.trangThai == DANG_MUON)
        {
            dem++;
		}
		cur = cur->tiep;
    }
    return dem;
}

void inPhieuDangMuon(NutPhieu* dau, string cmnd) {
	NutPhieu* cur = dau;
    while (cur!=NULL)
    {
        if(cur->thongTin.trangThai == DANG_MUON)
        {
			cout << cur->thongTin.maPhieu << "_ISBN" << cur->thongTin.isbnSach<<"_CMND"<<cur->thongTin.cmndDocGia<<"_han tra"<<cur->thongTin.ngayHenTra << endl;
		}
		cur = cur->tiep;
    }
}

void thongKeTop10SachMuonNhieuNhat(NutPhieu* dau) {
    string dsIsbn[1000];
    int dsSoLuot[1000];
    int soLuongKhacNhau = 0;
	NutPhieu* cur = dau;
    while (cur != NULL) {
		string isbn = cur->thongTin.isbnSach;
        int viTri = -1;
        for (int i = 0; i < soLuongKhacNhau; i++)
        {
            if(dsIsbn[i] == isbn) {
                viTri = i;
                break;
			}
        }
        if(viTri==-1) {
            dsIsbn[soLuongKhacNhau] = isbn;
            dsSoLuot[soLuongKhacNhau] = 1;
            soLuongKhacNhau++;
        } else {
            dsSoLuot[viTri]++;
		}
		cur = cur->tiep;
    }
    for(int i=0; i < soLuongKhacNhau - 1; i++) {
        for(int j = 0; j < soLuongKhacNhau - 1 - i; j++) {
            if(dsSoLuot[j] < dsSoLuot[j+1]) {
                int tamSo = dsSoLuot[j];
				dsSoLuot[j] = dsSoLuot[j + 1];
				dsSoLuot[j + 1] = tamSo;
            }
        }
	}
    cout << "\nTop 10 sach duoc muon nhieu nhat la: ";
	int soLuongIn = (soLuongKhacNhau < 10) ? soLuongKhacNhau : 10;
    for (int i = 0; i < soLuongIn; i++) {
        cout << i + 1 << ".ISBN" << dsIsbn[i] << "_" << dsSoLuot[i] << "\nLuot muon";
    }
}

void thonKeTop10DocGiaMuonNhieuNhat(NutPhieu* dau) {
    string dsCmnd[1000];
    int dsSoLuot[1000];
    int soLuongKhacNhau = 0;
    NutPhieu* cur = dau;
    while (cur != NULL) {
        string cmnd = cur->thongTin.cmndDocGia;
        int viTri = -1;
        for (int i = 0; i < soLuongKhacNhau; i++)
        {
            if(dsCmnd[i] == cmnd) {
                viTri = i;
                break;
            }
        }
        if(viTri==-1) {
            dsCmnd[soLuongKhacNhau] = cmnd;
            dsSoLuot[soLuongKhacNhau] = 1;
            soLuongKhacNhau++;
        } 
        else {
            dsSoLuot[viTri]++;
        }
        cur = cur->tiep;
    }
    for(int i=0; i < soLuongKhacNhau - 1; i++) {
        for(int j = 0; j < soLuongKhacNhau - 1 - i; j++) {
            if(dsSoLuot[j] < dsSoLuot[j+1]) {
                int tamSo = dsSoLuot[j];
                dsSoLuot[j] = dsSoLuot[j + 1];
                dsSoLuot[j + 1] = tamSo;
				string tamChuoi = dsCmnd[j];
                dsCmnd[j] = dsCmnd[j + 1];
				dsCmnd[j + 1] = tamChuoi;
            }
        }
    }
    cout << "\nTop 10 doc gia muon nhieu nhat la: ";
    int soLuongIn = (soLuongKhacNhau < 10) ? soLuongKhacNhau : 10;
    for (int i = 0; i < soLuongIn; i++) {
        cout << i + 1 << ".CMND" << dsCmnd[i] << "_" << dsSoLuot[i] << "\nLuot muon";
	}
}
void inDanhSachPhieu(NutPhieu* dau) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        cout << cur->thongTin.maPhieu << " - " << cur->thongTin.isbnSach << endl;
        cur = cur->tiep;
    }
}
void giaiPhongDanhSachPhieu(NutPhieu* dau) {
    NutPhieu* cur = dau;
    while (cur != NULL) {
        NutPhieu* tiep = cur->tiep;
        delete cur;
        cur = tiep;
    }
}
