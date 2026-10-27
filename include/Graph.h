#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <map>
class Graph {
private:
    std::map<std::string, std::vector<std::string>> danhSachKe;
public:
    void themDinh(const std::string& dinh);
    void themCanh(const std::string& dinh1, const std::string& dinh2);
    std::vector<std::string> bfs(const std::string& dinhBatDau) const;
    std::vector<std::string> dfs(const std::string& dinhBatDau) const;
    bool coDinh(const std::string& dinh) const;
};

