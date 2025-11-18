#include "../include/Magazine.h"
#include <iostream>

Magazine::Magazine()
    : LibraryItem(), issueNumber(0), publisher("Unknown"), frequency("Monthly"){
        std::cout << "Magazine created: " << title << std::endl;
    }

Magazine::Magazine(const std::string& title, const std::string& publisher, int year, int issue, const std::string& frequency)
    : LibraryItem(title, "", year), issueNumber(issue), publisher(publisher), frequency(frequency) {
        std::cout << "Magazine parameterized created: " << title << std::endl;
    }

Magazine::~Magazine() {
    std::cout << "Magazine destructor: "<< title << std::endl;
}

void Magazine::displayInfo() const {
    std::cout << "MAGAZINE - Title: " << title
            <<", Publisher: "<< publisher
            <<", Year: "<< publicationYear
            <<", Issue Number: "<< issueNumber
            <<", Frequency: "<< frequency
            <<", Available: "<< (available ? "Yes" : "No")
            << std::endl;
}