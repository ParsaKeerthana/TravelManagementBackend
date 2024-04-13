// User.h

#pragma once

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& role);

    const std::string& getUsername() const;
    const std::string& getPassword() const; // Getter function for password
    const std::string& getRole() const;

private:
    std::string username;
    std::string password;
    std::string role;
};
