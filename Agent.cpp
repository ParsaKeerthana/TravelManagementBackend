//
// Created by Keerthana Parsa on 4/12/24.
//

#include "Agent.h"
#include "Agent.h"
#include <algorithm>
#include <iostream>
void Agent::addPackage(const Package& package) {
    // Here, you'd normally check for duplicates before adding
    packages.push_back(package);
}

bool Agent::editPackage(const std::string& packageId, const std::string& newName, const std::string& newDestination) {
    for (auto& pkg : packages) {
        if (pkg.getId() == packageId) {
            pkg.setName(newName);
            pkg.setDestination(newDestination);
            return true;
        }
    }
    std::cerr << "Package not found for ID: " << packageId << std::endl;
    return false;
}

bool Agent::deletePackage(const std::string& packageId) {
    auto it = std::remove_if(packages.begin(), packages.end(), [&packageId](const Package& pkg) {
        return pkg.getId() == packageId;
    });

    if (it != packages.end()) {
        packages.erase(it, packages.end());
        return true;
    } else {
        std::cerr << "Package not found for ID: " << packageId << std::endl;
        return false;
    }
}
// Additional methods for searching, filtering, etc. can be implemented here
#include "Agent.h"
// ... other includes ...

std::vector<std::string> Agent::getAvailablePackagesInfo() const {
    std::vector<std::string> availablePackages;
    for (const auto& pkg : packages) {
        if (pkg.getAvailableSlots() > 0) {
            std::string packageInfo = "Package ID: " + pkg.getId() +
                                      ", Name: " + pkg.getName() +
                                      ", Destination: " + pkg.getDestination() +
                                      ", Price: $" + std::to_string(pkg.getPrice()) +
                                      ", Duration: " + std::to_string(pkg.getDuration()) +
                                      " days, Available Slots: " + std::to_string(pkg.getAvailableSlots());
            availablePackages.push_back(packageInfo);
        }
    }
    return availablePackages;
}

