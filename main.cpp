#include <iostream>
#include <fstream>
#include <string>
#include "task1.h"
#include "task2.h"
#include "task3.h"




void create_demo_students_file(const std::string& path) {
    std::ofstream file(path);
    if (file.is_open()) {
        file << "Sokolov\nShped\nSulaev\nTrefilova\nKuzmin\n"
             << "Abdulina\nLidjigoryaev\nGarmaev\nGerasimenko\nKravtsov\nKravtsov\n"; 
        file.close();
    }
}

int main() {
    std::cout << "TASK 1" << std::endl;
    std::string students_file = "students.txt";
    create_demo_students_file(students_file);

    std::cout << "Loading initial students from file." << std::endl;
    enrolled(students_file);

    std::cout << "Enter additional student names to vote. Type 'end' to stop." << std::endl;
    std::string input_name;
    while (true) {
        std::cout << "Enter last name: ";
        std::cin >> input_name;
        if (input_name == "end") {
            break;
        }
        unenrolled(input_name);
    }
    print_voting_results();


    std::cout << "\nTASK 2" << std::endl;
    std::cout << "Creating HashTable for Praskoviya's Shop" << std::endl;
    HashTable shopTable;

    std::cout << "Table empty? " << (shopTable.empty() ? "Yes" : "No") << " | Size: " << shopTable.size() << std::endl;

    shopTable.insert("Cement_M500", 450.50);
    shopTable.insert("Brick_Red", 18.20);
    shopTable.insert("Hammer", 750.00);
    shopTable.insert("Nails_100mm", 120.00);

    std::cout << "\nState of Hash Table after insertions:" << std::endl;
    shopTable.print_table();

    std::cout << "\nSearching prices:" << std::endl;
    std::cout << "Price of Hammer: " << shopTable.search("Hammer") << " rub." << std::endl;
    std::cout << "Price of Unknown_Item: " << shopTable.search("Unknown_Item") << " rub. (not found)" << std::endl;

    std::cout << "\nRemoving 'Brick_Red'..." << std::endl;
    shopTable.remove("Brick_Red");
    std::cout << "Size now: " << shopTable.size() << std::endl;


    std::cout << "\nTASK 3" << std::endl;
    run_image_hash_task("image.png", "hash_results.txt");

    return 0;
}