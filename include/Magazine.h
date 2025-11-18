#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include <string>
#include <iostream>

class Magazine : public LibraryItem {
    private:
        int issueNumber;
        std::string publisher;
        std::string frequency;

    public:
        Magazine();
        Magazine(const std::string& title, const std::string& publisher, int year, int issue, const std::string& frequency);


        ~Magazine() override;        
        
        void displayInfo() const override;

        int getIssueNumber() const { return issueNumber;}
        std::string getPublisher() const { return publisher; }
        std::string getFrequency() const { return frequency;}

        bool operator==(const Magazine& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Magazine& magazine);

        const Magazine* getCurrentObject() const { return this; }
}; 


#endif