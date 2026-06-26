#include "task1.h"
#include <iostream>
#include <fstream>

const int TABLE_SIZE = 100;
std::vector<std::string> hashTable(TABLE_SIZE, "");
int unique_voters = 0;
int duplicate_count = 0;

size_t custom_hash(const std::string& str) {
    size_t hash_val = 0;
    size_t p = 31; 
    for (size_t i = 0; i < str.length(); ++i) {
        hash_val = (hash_val * p + static_cast<size_t>(str[i])) % TABLE_SIZE;
    }
    return hash_val;
}

void process_vote(const std::string& last_name) {
    if (last_name.empty()) return;

    size_t index = custom_hash(last_name);
    size_t start_index = index;

    while (!hashTable[index].empty()) {
        if (hashTable[index] == last_name) {
            duplicate_count++;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) {
            std::cerr << "Hash table is full" << std::endl;
            return;
        }
    }

    hashTable[index] = last_name;
    unique_voters++;
}

void enrolled(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return;
    }
    std::string name;
    while (file >> name) {
        process_vote(name);
    }
    file.close();
}

void unenrolled(const std::string& last_name) {
    process_vote(last_name);
}

void print_voting_results() {
    std::cout << "\nVoting Results" << std::endl;
    std::cout << "Number of voters: " << unique_voters << std::endl;
    std::cout << "Number of duplicates: " << duplicate_count << std::endl;
    std::cout << "Voters list:" << std::endl;
    for (const auto& name : hashTable) {
        if (!name.empty()) {
            std::cout << " - " << name << std::endl;
        }
    }
}