cmake_minimum_required(VERSION 3.12)
project(Menu)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.58.0 COMPONENTS filesystem program_options)

set(SOURCE_FILES
        main.cpp
        EApplication.cpp
        EApplication.h)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Menu ${SOURCE_FILES})
    target_link_libraries(Menu ${Boost_LIBRARIES})
endif()