// include/file_operations.h
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "Library.h"
#include "User.h"
#include <vector>
#include <string>

class FileOperations {
public:
    // 🔥 CHANGED: Load functions now take reference parameters instead of returning
    static void saveLibraryToFile(const Library& library, const std::string& filename);
    static void loadLibraryFromFile(Library& library, const std::string& filename);  // Changed
    
    static void saveUsersToFile(const std::vector<User>& users, const std::string& filename);
    static void loadUsersFromFile(std::vector<User>& users, const std::string& filename);  // Changed
    
    // Backup operations
    static void createBackup(const Library& library, const std::vector<User>& users);
    static void restoreFromBackup(Library& library, std::vector<User>& users, const std::string& backupDir);  // Changed
    
private:
    static std::string getCurrentTimestamp();
};

#endif // FILE_OPERATIONS_H