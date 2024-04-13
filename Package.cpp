//
// Created by Keerthana Parsa on 4/12/24.
//

#include "Package.h"


#include <iostream>

Package::Package(const std::string& id, const std::string& name, const std::string& destination, double price, int duration, int totalSlots)
        : id(id), name(name), destination(destination), price(price), duration(duration), totalSlots(totalSlots), bookedSlots(0) {}

bool Package::bookSlot() {
    if (bookedSlots < totalSlots) {
        bookedSlots++;
        return true;
    } else {
        std::cerr << "No more slots available for package: " << name << std::endl;
        return false;
    }
}

void Package::cancelSlot() {
    if (bookedSlots > 0) {
        bookedSlots--;
    } else {
        std::cerr << "No slots are booked for package: " << name << std::endl;
    }
}

// Implementations for accessor methods
std::string Package::getId() const { return id; }
std::string Package::getName() const { return name; }
std::string Package::getDestination() const { return destination; }
double Package::getPrice() const { return price; }
int Package::getDuration() const { return duration; }
int Package::getTotalSlots() const { return totalSlots; }
int Package::getBookedSlots() const { return bookedSlots; }
int Package::getAvailableSlots() const { return totalSlots - bookedSlots; }

// Implementations for mutator methods
void Package::setName(const std::string& newName) { name = newName; }
void Package::setDestination(const std::string& newDestination) { destination = newDestination; }
