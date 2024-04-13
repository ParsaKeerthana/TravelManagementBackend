#include "Agent.h"
#include "Package.h"
#include "UserManager.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>

int main() {
    std::vector<Package> packages;  // In a real application, this might be managed by an Agent or similar class
    int choice;
    UserManager userManager;
    Agent travelAgent;


    do {
        std::cout << "\nTourist Management System Menu\n";
        std::cout << "1. Add Package\n";
        std::cout << "2. Book Slot in Package\n";
        std::cout << "3. List Available Packages\n";
        std::cout << "4. Register New User\n";
        std::cout << "6. List All Users\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clearing buffer to handle newline characters before taking string inputs
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string id, name, destination;
                double price;
                int duration, totalSlots;

                std::cout << "Enter package ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter package name: ";
                std::getline(std::cin, name);
                std::cout << "Enter destination: ";
                std::getline(std::cin, destination);
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter duration (in days): ";
                std::cin >> duration;
                std::cout << "Enter total slots: ";
                std::cin >> totalSlots;

                Package newPackage(id, name, destination, price, duration, totalSlots);
                travelAgent.addPackage(newPackage);
                std::cout << "Package added successfully.\n";
                break;
            }
            case 2: {
                auto availablePackages = travelAgent.getAvailablePackagesInfo();
                std::cout << "\nAll available packages:\n";
                for (const auto& info : availablePackages) {
                    std::cout << info << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "\nAll available packages:\n";
                for (const auto& pkg : packages) {
                    if (pkg.getAvailableSlots() > 0) {
                        std::cout << "Package ID: " << pkg.getId()
                                  << ", Name: " << pkg.getName()
                                  << ", Destination: " << pkg.getDestination()
                                  << ", Price: $" << pkg.getPrice()
                                  << ", Duration: " << pkg.getDuration()
                                  << " days, Available Slots: " << pkg.getAvailableSlots()
                                  << std::endl;
                    }
                }
                break;
            }
            case 4: {
                std::string username, password, role;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter role (Admin/User): ";
                std::cin >> role;

                userManager.addUser(username, password, role);
                break;
            }
            case 6: {
                userManager.listUsers();
                break;
            }
            case 7: {
                std::cout << "Exiting the program.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice, please try again.\n";
            }
        }
    } while (choice != 7);

    return 0;
}
