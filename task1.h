#pragma once
#include <string>
#include <vector>

size_t custom_hash(const std::string& str);
void enrolled(const std::string& file_path);
void unenrolled(const std::string& last_name);
void print_voting_results();