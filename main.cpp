#include <iostream>
#include <string>
#include "List.hpp"

int main() {
    std::pmr::memory_resource* resource = std::pmr::new_delete_resource();

    LinkedList<int> int_list(resource);
    for (int i = 1; i <= 6; ++i) {
        int_list.push_back(i);
    }
    int_list.push_front(8);

    std::cout << "Integer List: ";
    int_list.print();
    std::cout << int_list.size() << "\n";
    int_list.pop_back();
    std::cout << int_list.size() << "\n" ;
    // Создание списка с Person
    LinkedList<std::string> string_list(resource);
    string_list.push_back("Alice");
    string_list.push_back("Bob");
    string_list.push_back("Charlie");

    std::cout << "String List: ";
    string_list.print();

    return 0;
}
