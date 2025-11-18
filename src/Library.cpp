// src/Library.cpp
#include "../include/Library.h"
#include <iostream>
#include <algorithm>

// Constructor
Library::Library(const std::string& name) : libraryName(name) {
    std::cout << "Library created: " << libraryName << std::endl;
}

// Destructor - clean up dynamically allocated items
Library::~Library() {
    std::cout << "Library destroyed: " << libraryName << std::endl;
    for (auto item : items) {
        delete item;
    }
    items.clear();
}

// 🔥 OPERATOR OVERLOADING IMPLEMENTATIONS

// += operator to add items
Library& Library::operator+=(LibraryItem* item) {
    items.push_back(item);
    std::cout << "Added item to library using += : " << item->getTitle() << std::endl;
    return *this;
}

// Subscript operator
LibraryItem* Library::operator[](size_t index) {
    if (index < items.size()) {
        return items[index];
    }
    return nullptr;
}

const LibraryItem* Library::operator[](size_t index) const {
    if (index < items.size()) {
        return items[index];
    }
    return nullptr;
}

// Function call operator - search by title
std::vector<LibraryItem*> Library::operator()(const std::string& title) const {
    std::vector<LibraryItem*> results;
    for (auto item : items) {
        if (item->getTitle() == title) {
            results.push_back(item);
        }
    }
    return results;
}

// Regular methods
void Library::addItem(LibraryItem* item) {
    items.push_back(item);
}

void Library::displayAllItems() const {
    std::cout << "\n=== " << libraryName << " - All Items ===" << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". ";
        items[i]->displayInfo();
    }
}

void Library::displayAvailableItems() const {
    std::cout << "\n=== " << libraryName << " - Available Items ===" << std::endl;
    int count = 1;
    for (auto item : items) {
        if (item->isAvailable()) {
            std::cout << count++ << ". ";
            item->displayInfo();
        }
    }
}

int Library::getTotalItems() const {
    return items.size();
}

// Search by author
std::vector<LibraryItem*> Library::searchByAuthor(const std::string& author) const {
    std::vector<LibraryItem*> results;
    for (auto item : items) {
        // We need to check if the item has getAuthor method
        // This is a limitation of our current design
        Book* book = dynamic_cast<Book*>(item);
        if (book && book->getAuthor() == author) {
            results.push_back(item);
        }
    }
    return results;
}

// Get all books
std::vector<Book*> Library::getAllBooks() const {
    std::vector<Book*> books;
    for (auto item : items) {
        Book* book = dynamic_cast<Book*>(item);
        if (book) {
            books.push_back(book);
        }
    }
    return books;
}

void Library::removeItem(const std::string& title) {
    items.erase(
        std::remove_if(items.begin(), items.end(),
            [&title](LibraryItem* item) {
                if (item->getTitle() == title) {
                    delete item;
                    return true;
                }
                return false;
            }),
        items.end()
    );
}