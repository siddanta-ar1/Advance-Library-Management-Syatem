// include/exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// 🔥 CUSTOM EXCEPTION CLASSES (Unit 7)

class LibraryException : public std::exception {
private:
    std::string message;

public:
    LibraryException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ItemNotFoundException : public LibraryException {
public:
    ItemNotFoundException(const std::string& title)
        : LibraryException("Item not found: " + title) {}
};

class ItemNotAvailableException : public LibraryException {
public:
    ItemNotAvailableException(const std::string& title)
        : LibraryException("Item not available: " + title) {}
};

class InvalidOperationException : public LibraryException {
public:
    InvalidOperationException(const std::string& operation)
        : LibraryException("Invalid operation: " + operation) {}
};

class FileIOException : public LibraryException {
public:
    FileIOException(const std::string& filename)
        : LibraryException("File I/O error: " + filename) {}
};

#endif // EXCEPTIONS_H