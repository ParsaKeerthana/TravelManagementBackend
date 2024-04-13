// User.cpp

#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& role)
        : username(username), password(password) {}

const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPassword() const {
    return password;
}

const std::string& User::getRole() const {
    return role;
}

