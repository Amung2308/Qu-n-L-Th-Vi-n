#include "HashTable.h"

int HashTable::hashFunction(const std::string& cmnd) const {
    (void)cmnd;
    return 0;
}

void HashTable::insert(const DocGia& docGia) {
    (void)docGia;
}

bool HashTable::search(const std::string& cmnd, DocGia& outDocGia) const {
    (void)cmnd;
    (void)outDocGia;
    return false;
}

bool HashTable::remove(const std::string& cmnd) {
    (void)cmnd;
    return false;
}

std::vector<DocGia> HashTable::getAll() const {
    std::vector<DocGia> result;
    for (const auto& bucket : buckets) {
        for (const auto& dg : bucket) {
            result.push_back(dg);
        }
    }
    return result;
}
