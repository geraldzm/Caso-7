cmake_minimum_required(VERSION 3.19)
project(Caso_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(utils logic models program)

add_executable(Caso_7
        program/Main.cpp
        models/Node.h utils/FileManager.h models/NodeInitializerInterface.h program/NodeInitializer.h logic/PasswordManager.cpp logic/PasswordManager.h logic/ProbabilisticCracker.cpp logic/ProbabilisticCracker.h models/PasswordCracker.h)