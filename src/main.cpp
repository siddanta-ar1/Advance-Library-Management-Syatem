#include <iostream>
#include "../include/LibraryItem.h"
#include "../include/Book.h"
#include "../include/Magazine.h" 


using namespace std;

int main() {
    cout << "=== Step 2: Testing Inheriance and Derived Classes ===" << endl;
    cout << "Initial total items: " << LibraryItem::getTotalItems() << endl;

    cout << "\n--- Creating Book Objects ---" << endl;

    Book book1("The C++ Programming Language", "Bjarne Stroustrup", 2013,
                "978-0321563842", 1366, "Programming");
    Book book2("Clean Code", "Robert C. Martin", 2008,
                "978-0132350884", 464, "Software Engineering");
    
    cout << "\n--- Creating Magazine Objects ---" << endl;

    Magazine mag1("National Geographic", "National Geographic Partners", 2024, 1, "Monthly");
    Magazine mag2("Time", "Time USA, LLC", 2024, 12, "Weekly");

    cout << "\n--- Testing Inheritance Features ---" << endl;
    cout << "Book 1 Title: " << book1.getTitle() << endl;
    cout << "Book 1 Available Status: " << (book1.isAvailable() ? "Yes" : "No") << endl;

    cout << "\n Final total items: " << LibraryItem::getTotalItems() << endl;
    cout << "\n--- Displaying Book Info ---" << endl;
    book1.displayInfo();
    book2.displayInfo();
    cout << "\n--- Displaying Magazine Info ---" << endl;
    mag1.displayInfo();
    mag2.displayInfo();
    cout << "\n=== End of Step 2 ===" << endl;

    return 0;

}