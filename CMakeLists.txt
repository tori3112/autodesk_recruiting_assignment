cmake_minimum_required(VERSION 3.16)

project(autodesk_recruiting_assignment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autodesk_recruiting_assignment main.cpp
    item.cpp
    item.h
    inventory.h inventory.cpp
    flower_list.txt)

include(GNUInstallDirs)
install(TARGETS autodesk_recruiting_assignment
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
