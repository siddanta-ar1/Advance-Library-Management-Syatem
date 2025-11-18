#include "../include/Book.h"
#include <iostream>

Book::Book()
    : LibraryItem(), ISBN("000-0-00-000000-0"), pageCount(0), genre("Unknown") {
        std::cout << "Book created: " << title << std::endl;
    }

Book::Book(const std::string& title, const std::string& author, int year,
           const std::string& isbn, int pages, const std::string& genre)
    : LibraryItem(title, author, year), ISBN(isbn), pageCount(pages), genre(genre) {
        std::cout << "Book created: "<< title << std::endl;
    }

Book::~Book() {
    std::cout << "Book destroyed: "<< title << std::endl;
}

void Book::displayInfo() const {
    std::cout << "Book - Title: " << title
            <<", Author: "<< author
            <<", Year: "<< publicationYear
            <<", ISBN: "<< ISBN
            <<", Pages: "<< pageCount
            <<", Genre: "<< genre
            <<", Available: "<< (available ? "Yes" : "No")
            << std::endl;
}