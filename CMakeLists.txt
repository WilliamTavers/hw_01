cmake_minimum_required(VERSION 3.16)

project(hw_01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_01
    main.cpp
    mat4.h
    vec4.h
    mat4.cpp
    vec4.cpp
)

include(GNUInstallDirs)
install(TARGETS hw_01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
