#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <string>
#include <iostream>

class Book : public LibraryItem {
    private: 
        std::string ISBN;
        int pageCount;
        std::string genre;

    public:
        Book();
        Book(const std::string& title, const std::string& author, int year,
            const std::string& isbn, int pages, const std::string& genre);
        
        ~Book() override;
        
        void displayInfo() const override;

        std::string getISBN() const { return ISBN; };
        int getPageCount() const { return pageCount; };
        std::string getGenre() const { return genre; };
        
        void setISBN(const std::string& isbn) { ISBN = isbn; };
        void setPageCount(int pages) { pageCount = pages; };
        void setGenre(const std::string& g ) { genre = g; };

        


};

#endif