#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

// Do thi vo huong, bieu dien bang danh sach ke (adjacency list).
// Dinh = the loai sach (hoac co the la ISBN, tuy cach thiet ke).
// Ap dung: goi y sach cung the loai bang BFS/DFS - muc 3.5 va muc 4, dong 6.
class Graph {
private:
    std::map<std::string, std::vector<std::string>> danhSachKe;

public:
    void themDinh(const std::string& dinh);
    void themCanh(const std::string& dinh1, const std::string& dinh2);

    // Tra ve danh sach dinh theo thu tu duyet BFS tu dinh bat dau.
    std::vector<std::string> bfs(const std::string& dinhBatDau) const;

    // Tra ve danh sach dinh theo thu tu duyet DFS tu dinh bat dau.
    std::vector<std::string> dfs(const std::string& dinhBatDau) const;

    bool coDinh(const std::string& dinh) const;
};

#endif // GRAPH_H
