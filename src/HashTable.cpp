#include "HashTable.h"

int HashTable::hashFunction(const std::string& cmnd) const {
    // TODO (Tuan 4): thay the bang ham bam thuc su. Stub nay luon tra ve bucket 0
    // nen chua the dung duoc - CAN cai dat truoc khi insert/search hoat dong dung.
    (void)cmnd;
    return 0;
}

void HashTable::insert(const DocGia& docGia) {
    // TODO (Tuan 4): tinh index = hashFunction(docGia.cmnd) % buckets.size(), kiem
    // tra trung cmnd trong buckets[index] (neu trung thi cap nhat), neu chua co
    // thi push_back vao buckets[index] va tang soPhanTu.
    (void)docGia;
}

bool HashTable::search(const std::string& cmnd, DocGia& outDocGia) const {
    // TODO (Tuan 4): tinh index, duyet list tai buckets[index] de tim cmnd trung.
    (void)cmnd;
    (void)outDocGia;
    return false;
}

bool HashTable::remove(const std::string& cmnd) {
    // TODO (Tuan 4): tinh index, tim va xoa phan tu co cmnd trung trong buckets[index].
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
