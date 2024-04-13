cmake_minimum_required(VERSION 3.27)
project(TravelManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(TravelManagement main.cpp
        User.cpp
        User.h
        UserManager.cpp
        UserManager.h
        Package.cpp
        Package.h
        Agent.cpp
        Agent.h)
