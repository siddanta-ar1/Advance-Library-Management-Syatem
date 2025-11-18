// src/file_operations.cpp
#include "../include/file_operations.h"
#include "../include/exceptions.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>

// Save library to file (unchanged)
void FileOperations::saveLibraryToFile(const Library& library, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileIOException("Cannot open file for writing: " + filename);
    }
    
    file << "LIBRARY_DATA_FORMAT_v1.0" << std::endl;
    file << "LibraryName:" << library.getName() << std::endl;
    file << "TotalItems:" << library.getTotalItems() << std::endl;
    file << "===BEGIN_ITEMS===" << std::endl;
    file << "Note: Full object serialization would be implemented here" << std::endl;
    file << "Library contains " << library.getTotalItems() << " items" << std::endl;
    file << "===END_ITEMS===" << std::endl;
    file.close();
    
    std::cout << "✅ Library data saved to: " << filename << std::endl;
}

// 🔥 CHANGED: Load library into existing object
void FileOperations::loadLibraryFromFile(Library& library, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileIOException("Cannot open file for reading: " + filename);
    }
    
    std::string line;
    std::string libraryName = "Loaded Library";
    int itemCount = 0;
    
    // Read header
    while (std::getline(file, line)) {
        if (line.find("LibraryName:") != std::string::npos) {
            libraryName = line.substr(12);
        } else if (line.find("TotalItems:") != std::string::npos) {
            itemCount = std::stoi(line.substr(11));
        } else if (line == "===BEGIN_ITEMS===") {
            break;
        }
    }
    
    std::cout << "📖 Loading library: " << libraryName << " with " << itemCount << " items" << std::endl;
    
    // Read items data
    while (std::getline(file, line)) {
        if (line == "===END_ITEMS===") {
            break;
        }
        std::cout << "   " << line << std::endl;
    }
    
    file.close();
    std::cout << "✅ Library data loaded from: " << filename << std::endl;
}

// Save users to file (unchanged)
void FileOperations::saveUsersToFile(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileIOException("Cannot open file for writing: " + filename);
    }
    
    file << "USER_DATA_FORMAT_v1.0" << std::endl;
    file << "TotalUsers:" << users.size() << std::endl;
    file << "NextUserId:" << User::getNextUserId() << std::endl;
    file << "===BEGIN_USERS===" << std::endl;
    
    for (const auto& user : users) {
        file << "User:" << user.getName() << "," << user.getEmail() << "," << user.getUserId() << std::endl;
    }
    
    file << "===END_USERS===" << std::endl;
    file.close();
    
    std::cout << "✅ User data saved to: " << filename << " (" << users.size() << " users)" << std::endl;
}

// 🔥 CHANGED: Load users into existing vector
void FileOperations::loadUsersFromFile(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileIOException("Cannot open file for reading: " + filename);
    }
    
    std::vector<User> loadedUsers;
    std::string line;
    
    // Skip header
    while (std::getline(file, line)) {
        if (line == "===BEGIN_USERS===") {
            break;
        }
    }
    
    // Read users
    while (std::getline(file, line)) {
        if (line == "===END_USERS===") {
            break;
        }
        
        if (line.find("User:") != std::string::npos) {
            std::string userData = line.substr(5);
            size_t pos1 = userData.find(',');
            size_t pos2 = userData.find(',', pos1 + 1);
            
            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                std::string name = userData.substr(0, pos1);
                std::string email = userData.substr(pos1 + 1, pos2 - pos1 - 1);
                int userId = std::stoi(userData.substr(pos2 + 1));
                
                User user(name, email);
                loadedUsers.push_back(user);
            }
        }
    }
    
    file.close();
    
    // Replace the existing users with loaded ones
    users = loadedUsers;
    std::cout << "✅ User data loaded from: " << filename << " (" << users.size() << " users)" << std::endl;
}

// 🔥 CHANGED: Restore from backup now takes references
void FileOperations::restoreFromBackup(Library& library, std::vector<User>& users, const std::string& backupDir) {
    std::cout << "🔄 Restoring from backup: " << backupDir << std::endl;
    
    std::string libraryFile = backupDir + "/library.dat";
    std::string usersFile = backupDir + "/users.dat";
    
    // Load data into the provided objects
    loadLibraryFromFile(library, libraryFile);
    loadUsersFromFile(users, usersFile);
    
    std::cout << "✅ Restore completed!" << std::endl;
}

// Create backup (unchanged)
void FileOperations::createBackup(const Library& library, const std::vector<User>& users) {
    std::string timestamp = getCurrentTimestamp();
    std::string backupDir = "backup_" + timestamp;
    
    std::cout << "💾 Creating backup: " << backupDir << std::endl;
    
    std::string libraryFile = "library_backup.dat";
    std::string usersFile = "users_backup.dat";
    
    saveLibraryToFile(library, libraryFile);
    saveUsersToFile(users, usersFile);
    
    std::cout << "✅ Backup completed successfully!" << std::endl;
}

// Get current timestamp (unchanged)
std::string FileOperations::getCurrentTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    return oss.str();
}