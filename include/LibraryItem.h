#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

class LibraryItem {
    protected:
        std::string title;
        std::string author;
        int publicationYear;
        bool available;
        static int totalItems;

    public:
        LibraryItem();
        LibraryItem(const std::string& title, const std::string& author, int year);
        virtual ~LibraryItem();
        
        virtual void displayInfo() const = 0;
        
        std::string getTitle() const { return title;};
        std::string getAuthor() const { return author; };
        bool isAvailable() const { return available; };
        static int getTotalItems() { return totalItems; };
        
         void setAvailable(bool status) { available = status; }

        static void initializeStatic() { totalItems = 0; }
};

#endif 