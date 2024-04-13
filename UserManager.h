#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>
#include <iostream>

class UserManager {
public:
    bool addUser(const std::string& username, const std::string& password, const std::string& role);
    void listUsers() const;

private:
    std::vector<User> users;
};

#endif // USERMANAGER_H
