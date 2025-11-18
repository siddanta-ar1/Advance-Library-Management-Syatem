#include "../include/Book.h"
#include <iostream>
#include <sstream>

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
    std::cout << "📚 Book - Title: " << title
            <<", Author: "<< author
            <<", Year: "<< publicationYear
            <<", ISBN: "<< ISBN
            <<", Pages: "<< pageCount
            <<", Genre: "<< genre
            <<", Available: "<< (available ? "Yes" : "No")
            << std::endl;
}  

bool Book::operator==(const Book& other) const {
    return this->ISBN == other.ISBN;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}

bool Book::operator<(const Book& other)const {
    return this->title < other.title;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        this->title = other.title;
        this->author = other.author;
        this->publicationYear = other.publicationYear;
        this->available = other.available;
        this->ISBN = other.ISBN;
        this->pageCount = other.pageCount;
        this->genre = other.genre;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "📚 Book[Title: " << book.title
       <<",Author: "<< book.author
       <<",ISBN: "<< book.ISBN
       <<",Year: "<< book.publicationYear
       <<"]";
       return os;
}

Book::operator std::string() const {
    std::stringstream ss;
    ss << title << " by " << author << " (" << publicationYear << ")";
    return ss.str();
}

bool isClassic(const Book& book) {
    return book.publicationYear < 2000;
}
