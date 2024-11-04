cmake_minimum_required(VERSION 3.18)
project(
    homework5_7                    
    VERSION 0.0.0
    DESCRIPTION "SkillBox 5.7 homework"
    LANGUAGES CXX
)   
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(homework5_7)

set (sources main.cpp)

target_sources(homework5_7 PRIVATE ${sources})