#pragma once
#include <string>
#include <vector>
#include <list>

struct HashNode {
    std::string item_name;
    double price;
};

class HashTable {
private:
    int capacity;
    int current_size;
    std::vector<std::list<HashNode>> table;

    int get_hash(const std::string& key) const;

public:
    HashTable(); 
    void insert(const std::string& item, double price);
    bool remove(const std::string& item);
    double search(const std::string& item) const; 
    bool empty() const;
    int size() const;
    void print_table() const; 
};