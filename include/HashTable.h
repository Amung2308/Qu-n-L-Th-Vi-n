#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <utility>

// Bang bam voi xu ly va cham bang separate chaining (danh sach lien ket tai moi bucket).
// Ap dung: quan ly Doc gia theo CMND - muc 4, dong 3 cua de cuong.
template <typename Key, typename Value>
class HashTable {
private:
    static const int SO_BUCKET_MAC_DINH = 101; // so nguyen to, giam dung do (collision)

    std::vector<std::list<std::pair<Key, Value>>> buckets;
    int soPhanTu;

    // TODO (Tuan 4): viet ham bam phu hop cho Key = std::string (vd: polynomial rolling hash).
    // Luu y: can nap chong (overload) cho tung kieu Key neu dung nhieu kieu khac nhau.
    int hashFunction(const Key& key) const;

public:
    HashTable() : buckets(SO_BUCKET_MAC_DINH), soPhanTu(0) {}

    void insert(const Key& key, const Value& value);
    bool search(const Key& key, Value& outValue) const;
    bool remove(const Key& key);
    int size() const { return soPhanTu; }

    // Dung cho thong ke (vd: thong ke doc gia theo loai the) - duyet tat ca phan tu.
    std::vector<std::pair<Key, Value>> getAll() const;
};

template <typename Key, typename Value>
int HashTable<Key, Value>::hashFunction(const Key& key) const {
    // TODO (Tuan 4): thay the bang ham bam thuc su. Stub nay luon tra ve bucket 0
    // nen chua the dung duoc - CAN cai dat truoc khi insert/search hoat dong dung.
    (void)key;
    return 0;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value) {
    // TODO (Tuan 4): tinh index = hashFunction(key) % buckets.size(), kiem tra trung key
    // (neu trung thi cap nhat value), neu chua co thi push_back vao buckets[index].
    (void)key;
    (void)value;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::search(const Key& key, Value& outValue) const {
    // TODO (Tuan 4): tinh index, duyet list tai buckets[index] de tim key trung.
    (void)key;
    (void)outValue;
    return false;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key& key) {
    // TODO (Tuan 4): tinh index, tim va xoa phan tu co key trung trong buckets[index].
    (void)key;
    return false;
}

template <typename Key, typename Value>
std::vector<std::pair<Key, Value>> HashTable<Key, Value>::getAll() const {
    std::vector<std::pair<Key, Value>> result;
    for (const auto& bucket : buckets) {
        for (const auto& kv : bucket) {
            result.push_back(kv);
        }
    }
    return result;
}

#endif // HASHTABLE_H
