cmake_minimum_required(VERSION 3.10)

project(CPlusPlusDesignPatterns)

# C++ standard tanımla (örneğin C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Kaynak dosyalarını ekleyin
set(SOURCES
    src/main.cpp
    src/DesignPatterns/AbstractFactory.cpp
    src/DesignPatterns/Adapter.cpp
    src/DesignPatterns/Bridge.cpp
    src/DesignPatterns/Builder.cpp
    src/DesignPatterns/ChainOfResponsibility.cpp




)

# İlgili hedef oluştur
add_executable(${PROJECT_NAME} ${SOURCES})
