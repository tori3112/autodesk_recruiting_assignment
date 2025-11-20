cmake_minimum_required(VERSION 3.16)

project(autodesk_recruiting_assignment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autodesk_recruiting_assignment main.cpp
    Item.cpp
    Item.h)

include(GNUInstallDirs)
install(TARGETS autodesk_recruiting_assignment
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
