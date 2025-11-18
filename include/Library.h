#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include <vector>
#include <memory>

class Library {
    private: 
        std::vector<LibraryItem*> item;
        std::string libraryName;

        Library(const Library&) = delete;
        Library& operator=(const Library&) = delete;
}

#endif 