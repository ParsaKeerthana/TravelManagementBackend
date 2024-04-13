//
// Created by Keerthana Parsa on 4/12/24.
//

#ifndef TRAVELMANAGEMENT_AGENT_H
#define TRAVELMANAGEMENT_AGENT_H

#include "Package.h"
#include <vector>
#include <string>
class Agent {
private:
    std::vector<Package> packages;

public:
    void addPackage(const Package& package);
    bool editPackage(const std::string& packageId, const std::string& newName, const std::string& newDestination);
    bool deletePackage(const std::string& packageId);
    std::vector<std::string> getAvailablePackagesInfo() const;

    // Additional methods for searching, filtering, etc. can be added here
};


#endif //TRAVELMANAGEMENT_AGENT_H
