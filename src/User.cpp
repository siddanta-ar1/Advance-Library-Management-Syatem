// src/User.cpp
#include "../include/User.h"
#include <algorithm>

// Static member initialization
int User::nextUserId = 1;

// Default constructor
User::User() : userId(nextUserId++), name("Unknown"), email("unknown@email.com") {}

// Parameterized constructor
User::User(const std::string& name, const std::string& email) 
    : userId(nextUserId++), name(name), email(email) {}

// Borrow an item
void User::borrowItem(const std::string& itemTitle) {
    // Check if already borrowed
    if (hasBorrowedItem(itemTitle)) {
        throw InvalidOperationException("User already borrowed: " + itemTitle);
    }
    
    // Check borrowing limit (max 5 items)
    if (borrowedItems.size() >= 5) {
        throw InvalidOperationException("Borrowing limit reached for user: " + name);
    }
    
    borrowedItems.push_back(itemTitle);
    std::cout << "✅ User " << name << " borrowed: " << itemTitle << std::endl;
}

// Return an item
void User::returnItem(const std::string& itemTitle) {
    auto it = std::find(borrowedItems.begin(), borrowedItems.end(), itemTitle);
    if (it == borrowedItems.end()) {
        throw InvalidOperationException("User didn't borrow: " + itemTitle);
    }
    
    borrowedItems.erase(it);
    std::cout << "✅ User " << name << " returned: " << itemTitle << std::endl;
}

// Check if user has borrowed an item
bool User::hasBorrowedItem(const std::string& itemTitle) const {
    return std::find(borrowedItems.begin(), borrowedItems.end(), itemTitle) != borrowedItems.end();
}

// Display user information
void User::displayInfo() const {
    std::cout << "👤 USER - ID: " << userId 
              << ", Name: " << name 
              << ", Email: " << email 
              << ", Borrowed Items: " << borrowedItems.size() << std::endl;
    
    if (!borrowedItems.empty()) {
        std::cout << "   Currently borrowing:" << std::endl;
        for (const auto& item : borrowedItems) {
            std::cout << "   - " << item << std::endl;
        }
    }
}

// Equality operator
bool User::operator==(const User& other) const {
    return userId == other.userId;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User[ID: " << user.userId << ", Name: " << user.name << ", Email: " << user.email << "]";
    return os;
}