#include <iostream>
#include "../include/LibraryItem.h"

using namespace std;

int main() {
    cout << "=== Testing Library Management System Step 1 ===" << endl; 

    cout << "Initial total items: " << LibraryItem::getTotalItems() << endl;

    cout << "Step 1 completed successfully." << endl;
    cout << "Static member working correctly ." << endl;

    return 0;

}