// src/main.cpp
#include <iostream>
#include <vector>
#include <limits>
#include "../include/Library.h"
#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/User.h"
#include "../include/file_operations.h"
#include "../include/templates.h"
#include "../include/exceptions.h"

using namespace std;

class LibraryManager {
private:
    Library library;
    vector<User> users;
    int nextUserId;

public:
    LibraryManager() : library("Central Public Library"), nextUserId(1) {
        // Add some sample data
        initializeSampleData();
    }

    void showMainMenu();
    void addBook();
    void addMagazine();
    void displayAllItems();
    void searchItems();
    void borrowItem();
    void returnItem();
    void manageUsers();
    void saveToFiles();
    void loadFromFiles();
    void showStatistics();
    void initializeSampleData();

private:
    void showUserMenu();
    void addNewUser();
    void displayAllUsers();
    void showSearchMenu();
    void searchByTitle();
    void searchByAuthor();
    void searchByYear();
};

void LibraryManager::initializeSampleData() {
    // Add sample books
    library.addItem(new Book("The C++ Programming Language", "Bjarne Stroustrup", 2013,
                            "978-0321563842", 1368, "Programming"));
    library.addItem(new Book("Clean Code", "Robert C. Martin", 2008,
                            "978-0132350884", 464, "Software Engineering"));
    library.addItem(new Book("Design Patterns", "Erich Gamma", 1994,
                            "978-0201633610", 395, "Software Engineering"));
    
    // Add sample magazines
    library.addItem(new Magazine("National Geographic", "National Geographic Society", 2024,
                               245, "Monthly"));
    library.addItem(new Magazine("Time", "Time USA", 2024, 15, "Weekly"));
    
    // Add sample users
    users.push_back(User("Alice Johnson", "alice@email.com"));
    users.push_back(User("Bob Smith", "bob@email.com"));
    users.push_back(User("Carol Davis", "carol@email.com"));
}

void LibraryManager::showMainMenu() {
    int choice;
    
    do {
        cout << "\n=========================================" << endl;
        cout << "      LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "=========================================" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Add New Magazine" << endl;
        cout << "3. Display All Items" << endl;
        cout << "4. Search Items" << endl;
        cout << "5. Borrow Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "7. Manage Users" << endl;
        cout << "8. Show Statistics" << endl;
        cout << "9. Save to Files" << endl;
        cout << "10. Load from Files" << endl;
        cout << "0. Exit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        try {
            switch (choice) {
                case 1: addBook(); break;
                case 2: addMagazine(); break;
                case 3: displayAllItems(); break;
                case 4: searchItems(); break;
                case 5: borrowItem(); break;
                case 6: returnItem(); break;
                case 7: manageUsers(); break;
                case 8: showStatistics(); break;
                case 9: saveToFiles(); break;
                case 10: loadFromFiles(); break;
                case 0: cout << "Goodbye!" << endl; break;
                default: cout << "❌ Invalid choice!" << endl;
            }
        }
        catch (const exception& e) {
            cout << "💥 Error: " << e.what() << endl;
        }
        
    } while (choice != 0);
}

void LibraryManager::addBook() {
    cout << "\n--- Add New Book ---" << endl;
    
    string title, author, isbn, genre;
    int year, pages;
    
    cout << "Title: ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "Publication Year: ";
    cin >> year;
    cin.ignore();
    cout << "ISBN: ";
    getline(cin, isbn);
    cout << "Pages: ";
    cin >> pages;
    cin.ignore();
    cout << "Genre: ";
    getline(cin, genre);
    
    library.addItem(new Book(title, author, year, isbn, pages, genre));
}

void LibraryManager::addMagazine() {
    cout << "\n--- Add New Magazine ---" << endl;
    
    string title, publisher, frequency;
    int year, issue;
    
    cout << "Title: ";
    getline(cin, title);
    cout << "Publisher: ";
    getline(cin, publisher);
    cout << "Publication Year: ";
    cin >> year;
    cin.ignore();
    cout << "Issue Number: ";
    cin >> issue;
    cin.ignore();
    cout << "Frequency: ";
    getline(cin, frequency);
    
    library.addItem(new Magazine(title, publisher, year, issue, frequency));
}

void LibraryManager::displayAllItems() {
    library.displayAllItems();
}

void LibraryManager::searchItems() {
    showSearchMenu();
}

void LibraryManager::showSearchMenu() {
    int choice;
    
    do {
        cout << "\n--- Search Options ---" << endl;
        cout << "1. Search by Title" << endl;
        cout << "2. Search by Author" << endl;
        cout << "3. Search by Publication Year" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: searchByTitle(); break;
            case 2: searchByAuthor(); break;
            case 3: searchByYear(); break;
            case 0: return;
            default: cout << "❌ Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void LibraryManager::searchByTitle() {
    string title;
    cout << "Enter title to search: ";
    getline(cin, title);
    
    auto results = library(title); // Using function call operator
    cout << "Found " << results.size() << " items:" << endl;
    for (const auto& item : results) {
        item->displayInfo();
    }
}

void LibraryManager::searchByAuthor() {
    string author;
    cout << "Enter author to search: ";
    getline(cin, author);
    
    auto results = library.searchByAuthor(author);
    cout << "Found " << results.size() << " items:" << endl;
    for (const auto& item : results) {
        item->displayInfo();
    }
}

void LibraryManager::searchByYear() {
    int year;
    cout << "Enter publication year: ";
    cin >> year;
    
    // Using template-based search
    auto allBooks = library.getAllBooks();
    int count = 0;
    
    for (const auto& book : allBooks) {
        // In a real implementation, we'd have getPublicationYear()
        // For now, we'll use dynamic_cast to access base class members
        LibraryItem* item = dynamic_cast<LibraryItem*>(book);
        if (item) {
            // Note: publicationYear is protected, so we can't access it directly here
            // This demonstrates a limitation in our current design
        }
    }
    
    cout << "Search by year functionality would be implemented here" << endl;
}

void LibraryManager::borrowItem() {
    if (users.empty()) {
        cout << "❌ No users available. Please add users first." << endl;
        return;
    }
    
    cout << "\n--- Borrow Item ---" << endl;
    string title;
    cout << "Enter item title: ";
    getline(cin, title);
    
    // For simplicity, use first user
    // In real system, you'd select user
    try {
        library.borrowItem(title);
        users[0].borrowItem(title); // Associate with user
    }
    catch (const exception& e) {
        cout << "❌ " << e.what() << endl;
    }
}

void LibraryManager::returnItem() {
    if (users.empty()) {
        cout << "❌ No users available." << endl;
        return;
    }
    
    cout << "\n--- Return Item ---" << endl;
    string title;
    cout << "Enter item title: ";
    getline(cin, title);
    
    try {
        library.returnItem(title);
        users[0].returnItem(title); // Remove from user's borrowed items
    }
    catch (const exception& e) {
        cout << "❌ " << e.what() << endl;
    }
}

void LibraryManager::manageUsers() {
    showUserMenu();
}

void LibraryManager::showUserMenu() {
    int choice;
    
    do {
        cout << "\n--- User Management ---" << endl;
        cout << "1. Add New User" << endl;
        cout << "2. Display All Users" << endl;
        cout << "3. Show User Details" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: addNewUser(); break;
            case 2: displayAllUsers(); break;
            case 3: 
                if (!users.empty()) {
                    users[0].displayInfo(); // Show first user as example
                }
                break;
            case 0: return;
            default: cout << "❌ Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void LibraryManager::addNewUser() {
    cout << "\n--- Add New User ---" << endl;
    
    string name, email;
    cout << "Name: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    
    users.push_back(User(name, email));
    cout << "✅ User added successfully!" << endl;
}

void LibraryManager::displayAllUsers() {
    cout << "\n--- All Users ---" << endl;
    for (size_t i = 0; i < users.size(); ++i) {
        cout << i + 1 << ". ";
        users[i].displayInfo();
    }
}

void LibraryManager::showStatistics() {
    cout << "\n--- Library Statistics ---" << endl;
    cout << "Library: " << library.getName() << endl;
    cout << "Total Items: " << library.getTotalItems() << endl;
    cout << "Total Users: " << users.size() << endl;
    
    auto availableItems = library.findAvailableItems();
    cout << "Available Items: " << availableItems.size() << endl;
    
    auto allBooks = library.getAllBooks();
    cout << "Total Books: " << allBooks.size() << endl;
    
    // Calculate total borrowed items across all users
    int totalBorrowed = 0;
    for (const auto& user : users) {
        totalBorrowed += user.getBorrowedCount();
    }
    cout << "Total Borrowed Items: " << totalBorrowed << endl;
}

void LibraryManager::saveToFiles() {
    try {
        FileOperations::saveLibraryToFile(library, "library_data.dat");
        FileOperations::saveUsersToFile(users, "users_data.dat");
        FileOperations::createBackup(library, users);
        cout << "✅ All data saved successfully!" << endl;
    }
    catch (const exception& e) {
        cout << "❌ Save failed: " << e.what() << endl;
    }
}

void LibraryManager::loadFromFiles() {
    try {
        // 🔥 CORRECTED: Use the new function signatures with references
        FileOperations::loadLibraryFromFile(library, "library_data.dat");
        FileOperations::loadUsersFromFile(users, "users_data.dat");
        
        cout << "✅ All data loaded successfully!" << endl;
        cout << "Note: In full implementation, loaded data would replace current data" << endl;
    }
    catch (const exception& e) {
        cout << "❌ Load failed: " << e.what() << endl;
    }
}
int main() {
    cout << "=========================================" << endl;
    cout << "   WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "=========================================" << endl;
    cout << "Built with C++ OOP Concepts" << endl;
    cout << "Inheritance, Polymorphism, Templates," << endl;
    cout << "Exception Handling, File I/O, and more!" << endl;
    cout << "=========================================" << endl;
    
    LibraryManager manager;
    manager.showMainMenu();
    
    return 0;
}