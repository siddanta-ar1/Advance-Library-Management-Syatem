// include/templates.h
#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <vector>
#include <algorithm>
#include <iostream>

// 🔥 FUNCTION TEMPLATES (Unit 7)

// Template function to find element in any container
template<typename Container, typename T>
bool contains(const Container& container, const T& value) {
    return std::find(container.begin(), container.end(), value) != container.end();
}

// Template function to print any container
template<typename Container>
void printContainer(const Container& container, const std::string& name = "Container") {
    std::cout << name << " [" << container.size() << " items]: ";
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Template function with multiple type parameters
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    
    void display() const {
        std::cout << "Pair(" << first << ", " << second << ")" << std::endl;
    }
};

// Template function for searching with custom criteria
template<typename T, typename Predicate>
std::vector<T*> findIf(const std::vector<T*>& container, Predicate pred) {
    std::vector<T*> results;
    for (const auto& item : container) {
        if (pred(item)) {
            results.push_back(item);
        }
    }
    return results;
}

#endif // TEMPLATES_H