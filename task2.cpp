#include "task2.h"
#include <iostream>

HashTable::HashTable() : capacity(10), current_size(0) {
    table.resize(capacity);
}

int HashTable::get_hash(const std::string& key) const {
    unsigned long hash_val = 0;
    for (char ch : key) {
        hash_val = hash_val * 37 + ch;
    }
    return hash_val % capacity;
}

void HashTable::insert(const std::string& item, double price) {
    int index = get_hash(item);
    
    for (auto& node : table[index]) {
        if (node.item_name == item) {
            node.price = price;
            return;
        }
    }
    
    table[index].push_back({item, price});
    current_size++;
}

bool HashTable::remove(const std::string& item) {
    int index = get_hash(item);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->item_name == item) {
            table[index].erase(it);
            current_size--;
            return true;
        }
    }
    return false;
}

double HashTable::search(const std::string& item) const {
    int index = get_hash(item);
    for (const auto& node : table[index]) {
        if (node.item_name == item) {
            return node.price;
        }
    }
    return -1.0; 
}

bool HashTable::empty() const {
    return current_size == 0;
}

int HashTable::size() const {
    return current_size;
}

void HashTable::print_table() const {
    for (int i = 0; i < capacity; ++i) {
        std::cout << "Cell " << i << ": ";
        for (const auto& node : table[i]) {
            std::cout << "[" << node.item_name << ": " << node.price << " rub] -> ";
        }
        std::cout << "nullptr" << std::endl;
    }
}