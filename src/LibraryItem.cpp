#include "../include/LibraryItem.h"

int LibraryItem::totalItems = 0;

LibraryItem::LibraryItem()
    : title("Unknown"), author("Unknown"), publicationYear(0), available(true) {
        totalItems++;
        std::cout << "LibraryItem created: " << title << std::endl;
    }

LibraryItem::LibraryItem(const std::string& title, const std::string& author, int year) 
    : title(title), author(author), publicationYear(year), available(true) {
        totalItems++;
        std::cout << "LibraryItem created: " << title << std::endl;
    }

LibraryItem::~LibraryItem() {
    totalItems--;
    std::cout << "LibraryItem destroyed: " << title << std::endl;
}
