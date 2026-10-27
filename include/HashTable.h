#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#include <list>
#include "DocGia.h"
class HashTable {
private:
    static const int SO_BUCKET_MAC_DINH = 101; 
    std::vector<std::list<DocGia>> buckets;
    int soPhanTu;
    int hashFunction(const std::string& cmnd) const;
public:
    HashTable() : buckets(SO_BUCKET_MAC_DINH), soPhanTu(0) {}
    void insert(const DocGia& docGia);
    bool search(const std::string& cmnd, DocGia& outDocGia) const;
    bool remove(const std::string& cmnd);
    int size() const { return soPhanTu; }
    std::vector<DocGia> getAll() const;
};

