// include/Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "exceptions.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<LibraryItem*> items;
    std::string libraryName;

public:
    // Constructor & Destructor
    Library(const std::string& name);
    ~Library();
    
    // Delete copy operations
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    
    // Operator Overloading (existing)
    Library& operator+=(LibraryItem* item);
    LibraryItem* operator[](size_t index);
    const LibraryItem* operator[](size_t index) const;
    std::vector<LibraryItem*> operator()(const std::string& title) const;
    
    // Regular methods with exception handling
    void addItem(LibraryItem* item);
    void removeItem(const std::string& title);
    void displayAllItems() const;
    void displayAvailableItems() const;
    int getTotalItems() const;
    
    // 🔥 NEW METHODS WITH EXCEPTION HANDLING
    void borrowItem(const std::string& title);
    void returnItem(const std::string& title);
    LibraryItem* findItem(const std::string& title) const;
    
    // Template-based search methods
    std::vector<LibraryItem*> searchByAuthor(const std::string& author) const;
    std::vector<Book*> getAllBooks() const;
    std::vector<LibraryItem*> findAvailableItems() const;
    
    // File operations with exception handling
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    std::string getName() const { return libraryName; }
};

#endif // LIBRARY_H