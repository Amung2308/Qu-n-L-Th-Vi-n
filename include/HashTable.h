#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include "DocGia.h"

// Bang bam voi xu ly va cham bang separate chaining (danh sach lien ket tai moi bucket).
// Ap dung: quan ly Doc gia theo CMND (muc 4, dong 3 cua de cuong).
class HashTable {
private:
    static const int SO_BUCKET_MAC_DINH = 101; // so nguyen to, giam dung do (collision)

    std::vector<std::list<DocGia>> buckets;
    int soPhanTu;

    // TODO (Tuan 4): viet ham bam phu hop cho chuoi CMND (vd: polynomial rolling hash,
    // cong ma ASCII cac ky tu nhan voi luy thua cua mot so nguyen to, roi % so bucket).
    int hashFunction(const std::string& cmnd) const;

public:
    HashTable() : buckets(SO_BUCKET_MAC_DINH), soPhanTu(0) {}

    void insert(const DocGia& docGia);
    bool search(const std::string& cmnd, DocGia& outDocGia) const;
    bool remove(const std::string& cmnd);
    int size() const { return soPhanTu; }

    // Dung cho thong ke (vd: thong ke doc gia theo loai the) - duyet tat ca phan tu.
    std::vector<DocGia> getAll() const;
};

#endif // HASHTABLE_H
