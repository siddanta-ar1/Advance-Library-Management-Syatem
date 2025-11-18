// src/main.cpp
#include <iostream>
#include <vector>
#include "../include/Library.h"
#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/templates.h"
#include "../include/exceptions.h"

using namespace std;

void testTemplates();
void testExceptionHandling();
void testLibraryWithExceptions();
void demonstrateTemplatesWithLibrary();

int main() {
    cout << "=== Step 4: Templates & Exception Handling ===" << endl;
    
    try {
        testTemplates();
        testExceptionHandling();
        testLibraryWithExceptions();
        demonstrateTemplatesWithLibrary();
        
        cout << "\n🎉 Step 4 completed successfully! ✅" << endl;
    }
    catch (const exception& e) {
        cout << "💥 Critical error in main: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

void testTemplates() {
    cout << "\n--- Testing Template Functions ---" << endl;
    
    // Test contains template
    vector<int> numbers = {1, 2, 3, 4, 5};
    cout << "Vector contains 3: " << contains(numbers, 3) << endl;
    cout << "Vector contains 10: " << contains(numbers, 10) << endl;
    
    vector<string> names = {"Alice", "Bob", "Charlie"};
    cout << "Names contain 'Bob': " << contains(names, string("Bob")) << endl;
    
    // Test printContainer template
    printContainer(numbers, "Numbers");
    printContainer(names, "Names");
    
    // Test Pair template
    Pair<string, int> nameAge("John", 25);
    nameAge.display();
    
    Pair<double, string> priceProduct(19.99, "Book");
    priceProduct.display();
}

void testExceptionHandling() {
    cout << "\n--- Testing Exception Handling ---" << endl;
    
    // Test basic exception handling
    try {
        vector<int> vec{1, 2, 3};
        cout << "Accessing element 10: ";
        cout << vec.at(10) << endl;  // This will throw
    }
    catch (const out_of_range& e) {
        cout << "❌ Caught out_of_range: " << e.what() << endl;
    }
    
    // Test custom exceptions
    try {
        throw ItemNotFoundException("The Great Gatsby");
    }
    catch (const LibraryException& e) {
        cout << "❌ Caught LibraryException: " << e.what() << endl;
    }
}

void testLibraryWithExceptions() {
    cout << "\n--- Testing Library with Exception Handling ---" << endl;
    
    Library library("Test Library");
    
    // Add some items
    Book* book1 = new Book("The C++ Programming Language", "Bjarne Stroustrup", 2013,
                          "978-0321563842", 1368, "Programming");
    library.addItem(book1);
    
    // Test borrowing and returning
    try {
        library.borrowItem("The C++ Programming Language");
        cout << "✅ Successfully borrowed book" << endl;
        
        // Try to borrow again (should fail)
        library.borrowItem("The C++ Programming Language");
    }
    catch (const ItemNotAvailableException& e) {
        cout << "❌ Expected error: " << e.what() << endl;
    }
    
    // Test returning
    try {
        library.returnItem("The C++ Programming Language");
        cout << "✅ Successfully returned book" << endl;
    }
    catch (const LibraryException& e) {
        cout << "❌ Error: " << e.what() << endl;
    }
    
    // Test finding non-existent item
    try {
        library.findItem("Non-Existent Book");
    }
    catch (const ItemNotFoundException& e) {
        cout << "❌ Expected error: " << e.what() << endl;
    }
    
    // Test file operations
    try {
        library.saveToFile("test_library.txt");
        library.loadFromFile("test_library.txt");
    }
    catch (const FileIOException& e) {
        cout << "❌ File error: " << e.what() << endl;
    }
}

void demonstrateTemplatesWithLibrary() {
    cout << "\n--- Demonstrating Templates with Library ---" << endl;
    
    Library library("Template Demo Library");
    
    // Add items
    library.addItem(new Book("Book A", "Author X", 2020, "111", 100, "Fiction"));
    library.addItem(new Book("Book B", "Author Y", 2019, "222", 200, "Science"));
    library.addItem(new Magazine("Magazine A", "Publisher X", 2024, 1, "Monthly"));
    
    // Use template function with library items
    auto allBooks = library.getAllBooks();
    
    // Create a vector of titles for template demonstration
    vector<string> titles;
    for (const auto& book : allBooks) {
        titles.push_back(book->getTitle());
    }
    
    printContainer(titles, "Book Titles");
    
    // Use findIf template with custom predicate
    auto availableItems = library.findAvailableItems();
    cout << "Available items: " << availableItems.size() << endl;
    
    // Demonstrate Pair template with library data
    Pair<string, int> libraryStats(library.getName(), library.getTotalItems());
    libraryStats.display();
}