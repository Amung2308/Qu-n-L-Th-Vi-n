#include <iostream>
#include "Sach.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include "GiaoDich.h"
#include "AVLTree.h"
#include "BSTree.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Graph.h"
#include "Trie.h"
#include "FileManager.h"
#include "Menu.h"
using namespace std;
const int SO_LUONG_TOI_DA = 1000;
const int SO_SACH_MUON_TOI_DA = 3;
const double TIEN_PHAT_MOI_NGAY = 5000;
int layNgay(string ngay) { return stoi(ngay.substr(0, 2)); }
int layThang(string ngay) { return stoi(ngay.substr(3, 2)); }
int layNam(string ngay) { return stoi(ngay.substr(6, 4)); }
int tinhSoNgay(string ngay) {
    return layNam(ngay) * 360 + layThang(ngay) * 30 + layNgay(ngay);
}
int main() {
    NutAVL* gocAVL = NULL;
    NutBST* gocBST = NULL;
    NutBam* bangDocGia[SO_BUCKET];
    khoiTaoBam(bangDocGia);
    NutPhieu* dauPhieu = NULL;
    NutPhieu* cuoiPhieu = NULL;
    MangDong lichSuGiaoDich;
    khoiTaoMang(lichSuGiaoDich);
    DoThi doThiTheLoai;
    khoiTaoDoThi(doThiTheLoai);
    NutTrie* gocTrie = taoNutTrie();
    int soPhieuDaTao = 1;
	Sach* dsSachNap = new Sach[SO_LUONG_TOI_DA];
    int soLuongSachNap = 0;
    if (docDanhSachSach("data/sach.dat", dsSachNap, soLuongSachNap, SO_LUONG_TOI_DA)) {
        for (int i = 0; i < soLuongSachNap; i++) {
            gocAVL = themAVL(gocAVL, dsSachNap[i]);
            gocBST = themBST(gocBST, dsSachNap[i]);
        }
        cout << "Da nap " << soLuongSachNap << "\nsach tu file.";
    }
	delete[] dsSachNap;
    DocGia dsDocGiaNap[SO_LUONG_TOI_DA];
    int soLuongDocGiaNap = 0;
    if (docDanhSachDocGia("data/docgia.dat", dsDocGiaNap, soLuongDocGiaNap, SO_LUONG_TOI_DA)) {
        for (int i = 0; i < soLuongDocGiaNap; i++) {
            themBam(bangDocGia, dsDocGiaNap[i]);
        }
        cout << "Da nap " << soLuongDocGiaNap << " doc gia tu file.\n";
    }
    bool dangChay = true;
    while (dangChay) {
        int chucNangChinh = hienThiMenuChinh();
        switch (chucNangChinh) {
        case 1: {
            bool oLaiMenuSach = true;
            while (oLaiMenuSach) {
                int luaChon = hienThiMenuQuanLySach();
                if (luaChon == 0) { oLaiMenuSach = false; break; }
                if (luaChon == 1) {
                    Sach s;
                    cout << "Nhap ISBN: ";
                    cin >> s.isbn;
                    cin.ignore();
                    cout << "Nhap ten sach: ";
                    getline(cin, s.tenSach);
                    cout << "Nhap tac gia: ";
                    getline(cin, s.tacGia);
                    cout << "Nhap the loai: ";
                    getline(cin, s.theLoai);
                    cout << "Nhap nam xuat ban: ";
                    cin >> s.namXuatBan;
                    cout << "Nhap so luong: ";
                    cin >> s.soLuong;
                    cin.ignore();
                    gocBST = themBST(gocBST, s);
                    gocAVL = themAVL(gocAVL, s);
                    themDinh(doThiTheLoai, s.isbn);
					Sach* dsTamthoi = new Sach[SO_LUONG_TOI_DA];
					int soLuongTamthoi = 0;
					layTatCaSachAVL(gocAVL, dsTamthoi, soLuongTamthoi);
                    for (int i = 0; i < soLuongTamthoi; i++) {
                        if (dsTamthoi[i].isbn != s.isbn && dsTamthoi[i].theLoai == s.theLoai) {
							themCanh(doThiTheLoai, s.isbn, dsTamthoi[i].isbn);
                        }
                    }
                    delete[] dsTamthoi;
                    cout << "\nDa them sach: ";
                }
                else if (luaChon == 2) {
					string isbnCanXoa;
					cout << "\nNhap ISBN can xoa: ";
                    cin >> isbnCanXoa;
					gocAVL = xoaAVL(gocAVL, isbnCanXoa);
                    cout << "\nDa xoa sach";
                }
                else if (luaChon == 4) {
                    string isbn;
                    cout << "Nhap ISBN can tim: ";
                    cin >> isbn;
                    NutAVL* ketqua = timAVL(gocAVL, isbn);
                    if (ketqua == NULL) {
                        cout << "\nKhong tim thay sach ";
                    }
                    else {
                        cout << "\nDa tim thay sach: " << ketqua->thongTin.tenSach << endl;
                    }
                }
                else if (luaChon == 5) {
                    inThuTuAVL(gocAVL);
                }
                else if (luaChon == 6) {
                    inThuTuBST(gocBST);
                }
                else {
                    cout << "\n[Dang phat trien]";
                }
            }
            break;
        }
        case 2: {
            bool oLaiMenuDocGia = true;
            while (oLaiMenuDocGia) {
                int luaChon = hienThiMenuQuanLyDocGia();
                if (luaChon == 0) { oLaiMenuDocGia = false; break; }
                if (luaChon == 1) {
                    DocGia dg;
                    cout << "Nhap CMND: ";
                    cin >> dg.cmnd;
                    cin.ignore();
                    cout << "Nhap ho ten: ";
                    getline(cin, dg.hoTen);
                    cout << "Nhap email: ";
                    getline(cin, dg.email);
                    cout << "Nhap SDT: ";
                    getline(cin, dg.sdt);
                    cout << "Nhap loai the (0=Sinh vien, 1=Giang vien, 2=VIP): ";
                    int loai;
                    cin >> loai;
                    cin.ignore();
                    dg.loaiThe = (LoaiThe)loai;
                    themBam(bangDocGia, dg);
                    cout << "\nDa them doc gia ";
                }
                else if (luaChon == 2) {
                    string cmndCanXoa;
                    cout << "Nhap CMND can xoa: ";
                    cin >> cmndCanXoa;
                    if (xoaBam(bangDocGia, cmndCanXoa)) cout << "\nDa xoa ";
                    else cout << "\nKhong tim thay CMND nay ";
                }
                else if (luaChon == 4) {
                    string cmndCanTim;
                    cout << "Nhap CMND can tim: ";
                    cin >> cmndCanTim;
                    DocGia ketQua;
                    if (timBam(bangDocGia, cmndCanTim, ketQua)) {
                        cout << "Tim thay: " << ketQua.cmnd << " - " << ketQua.hoTen << " - " << ketQua.email << "\n";
                    }
                    else {
                        cout << "\nKhong tim thay doc gia co CMND nay ";
                    }
                }
                else {
                    cout << "\n[Dang phat trien]";
                }
            }
            break;
        }
            case 3: {
                bool oLaiMenuMuonTra = true;
                while (oLaiMenuMuonTra) {
                    int luaChon = hienThiMenuMuonTra();
                    if (luaChon == 0) {
                        oLaiMenuMuonTra = false;
                        break;
                    }
                    if (luaChon == 1) {
                        string cmnd, isbn, ngayMuon, ngayHenTra;
						cout << "\nNhap CMND doc gia: ";
                        cin >> cmnd;
						DocGia dg;
                        if(!timBam(bangDocGia, cmnd, dg)) {
                            cout << "\nKhong tim thay doc gia co CMND nay.";
                        }
                        else {
							cout << "\nNhap ISBN sach: ";
							cin >> isbn;
							NutAVL* ketQuaSach = timAVL(gocAVL, isbn);
                            if (ketQuaSach == NULL) {
                                cout << "\nKhong tim thay sach nay.";
							}
                            else if (ketQuaSach->thongTin.soLuong <= 0) {
								cout << "\nSach nay da het.";
                            }
                            else if (demPhieuDangMuon(dauPhieu, cmnd) >= SO_SACH_MUON_TOI_DA) {
                                cout << "\nDa cho muon sach." << SO_SACH_MUON_TOI_DA << "cuon";
                            }
                            else {
								cin.ignore();
                                cout << "\nNhap ngay muon sach: ";
								getline(cin, ngayMuon);
								cout << "\nNhap ngay hen tra sach: ";
								getline(cin, ngayHenTra);
                                PhieuMuon p;
								p.maPhieu = "PM" + to_string(soPhieuDaTao++);
                                soPhieuDaTao++;
								p.cmndDocGia = cmnd;
								p.isbnSach = isbn;
								p.ngayMuon = ngayMuon;
								p.ngayHenTra = ngayHenTra;
								p.ngayTra = "";
								p.trangThai = DANG_MUON;
                                p.tienPhat = 0;
                                themCuoiPhieu(dauPhieu, cuoiPhieu, p);
                                ketQuaSach->thongTin.soLuong--;
								GiaoDich gd;
                                gd.maPhieu = p.maPhieu;
                                gd.loaiGiaoDich = "Muon";
                                gd.ngayThucHien = ngayMuon;
                                themVaoCuoiMang(lichSuGiaoDich, gd);
                                cout << "\nDa lap phieu muon: " << p.maPhieu << "\n";
                            }
                        }
                    }
                    else if (luaChon == 2) {
                        string maPhieu, ngayTra;
                        cout << "\nNhap ma phieu can tra sach: ";
                        cin >> maPhieu;
						PhieuMuon* p = timTheoMaPhieu(dauPhieu, maPhieu);
                        if (p == NULL) {
                            cout << "\nKhong tim thay phieu muon nay.";
                        }
                        else if (p->trangThai == DA_TRA) {
                            cout << "\nPhieu nay da tra roi.";
                        }
                        else {
							cin.ignore();
							cout << "\nNhap ngay tra sach: ";
							getline(cin, ngayTra);
                            p->ngayTra = ngayTra;
							p->trangThai = DA_TRA;
                            if (tinhSoNgay(ngayTra) > tinhSoNgay(p->ngayHenTra)) {
								int soNgayTre = tinhSoNgay(ngayTra) - tinhSoNgay(p->ngayHenTra);
                                p->tienPhat = soNgayTre * TIEN_PHAT_MOI_NGAY;
                                cout << "\nTra tre" << soNgayTre << " ngay, tien phat: " << p->tienPhat << " \ndong";
                            }
                            else {
                                cout << "\nTra dung han.";
                            }
							NutAVL* ketQuaSach = timAVL(gocAVL, p->isbnSach);
                            if(ketQuaSach != NULL) {
                                ketQuaSach->thongTin.soLuong++;
							}
							GiaoDich gd;
                            gd.maPhieu = p->maPhieu;
                            gd.loaiGiaoDich = "Tra";
                            gd.ngayThucHien = ngayTra;
                            themVaoCuoiMang(lichSuGiaoDich, gd);
							cout << "\nDa tra sach va cap nhat phieu muon.\n";
                        }
                    }
                    else if (luaChon == 3) {
                        inPhieuDangMuon(dauPhieu,"");
                    }
                    else {
						cout << "[Dang phat trien]";
                    }
                }
                break;
            }
            case 4: {
                bool oLaiMenuThongKe = true;
                while (oLaiMenuThongKe) {
                    int luaChon = hienThiMenuThongKe();
                    if (luaChon == 0) { oLaiMenuThongKe = false; break; }
                    cout << "\n[Dang phat trien]";
                }
                break;
            }
            case 5: {
                bool oLaiMenuGoiY = true;
                while (oLaiMenuGoiY) {
                    int luaChon = hienThiMenuGoiYTimKiem();
                    if (luaChon == 0) { oLaiMenuGoiY = false; break; }
                    cout << "\n[Dang phat trien]";
                }
                break;
            }
            case 0:
                dangChay = false;
                cout << "\nCam on da su dung chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le, vui long thu lai.\n";
                break;
        }
        Sach dsSachLuu[SO_LUONG_TOI_DA];
        int soLuongSachLuu = 0;
        layTatCaSachAVL(gocAVL, dsSachLuu, soLuongSachLuu);
        ghiDanhSachSach("data/sach.dat", dsSachLuu, soLuongSachLuu);
        DocGia dsDocGiaLuu[SO_LUONG_TOI_DA];
        int soLuongDocGiaLuu = 0;
        layTatCaDocGiaBam(bangDocGia, dsDocGiaLuu, soLuongDocGiaLuu);
        ghiDanhSachDocGia("data/docgia.dat", dsDocGiaLuu, soLuongDocGiaLuu);
        cout << "Da luu " << soLuongSachLuu << " sach va " << soLuongDocGiaLuu << "\ndoc gia ra file.";
    }

    giaiPhongAVL(gocAVL);
    giaiPhongBST(gocBST);
    giaiPhongBam(bangDocGia);
    giaiPhongDanhSachPhieu(dauPhieu);
    giaiPhongMang(lichSuGiaoDich);
    giaiPhongTrie(gocTrie);

    return 0;
}

