//
// Created by Keerthana Parsa on 4/12/24.
//

#ifndef TRAVELMANAGEMENT_PACKAGE_H
#define TRAVELMANAGEMENT_PACKAGE_H


#include <string>

class Package {
private:
    std::string id;
    std::string name;
    std::string destination;
    double price;
    int duration; // Duration in days
    int totalSlots;
    int bookedSlots;

public:
    Package(const std::string& id, const std::string& name, const std::string& destination, double price, int duration, int totalSlots);

    bool bookSlot();
    void cancelSlot();

    // Accessor methods for package details
    std::string getId() const;
    std::string getName() const;
    std::string getDestination() const;
    double getPrice() const;
    int getDuration() const;
    int getTotalSlots() const;
    int getBookedSlots() const;
    int getAvailableSlots() const;

    // Mutator methods to allow editing package details
    void setName(const std::string& newName);
    void setDestination(const std::string& newDestination);
    // ... Other accessors and mutators
};


#endif //TRAVELMANAGEMENT_PACKAGE_H
