// include/User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include "exceptions.h"

class User {
private:
    int userId;
    std::string name;
    std::string email;
    std::vector<std::string> borrowedItems;
    static int nextUserId;

public:
    // Constructors
    User();
    User(const std::string& name, const std::string& email);
    
    // Getters
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    const std::vector<std::string>& getBorrowedItems() const { return borrowedItems; }
    static int getNextUserId() { return nextUserId; }
    
    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    
    // User operations
    void borrowItem(const std::string& itemTitle);
    void returnItem(const std::string& itemTitle);
    bool hasBorrowedItem(const std::string& itemTitle) const;
    int getBorrowedCount() const { return borrowedItems.size(); }
    
    // Display
    void displayInfo() const;
    
    // Operator overloading
    bool operator==(const User& other) const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif // USER_H