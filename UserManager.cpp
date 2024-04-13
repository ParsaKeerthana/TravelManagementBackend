// UserManager.cpp
#include "UserManager.h"


bool UserManager::addUser(const std::string& username, const std::string& password, const std::string& role) {
    // Check if user already exists
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            std::cout << "Registration failed: User already exists." << std::endl;
            return false;
        }
    }

    // Add new user if not found
    users.emplace_back(username, password, role);
    std::cout << "User successfully registered." << std::endl;
    return true;
}

void UserManager::listUsers() const {
    if (users.empty()) {
        std::cout << "No registered users." << std::endl;
        return;
    }
    for (const auto& user : users) {
        std::cout << "Username: " << user.getUsername() << ", Role: " << user.getRole() << std::endl;
    }
}
