cmake_minimum_required(VERSION 3.26)
project(testsfml)

set(CMAKE_CXX_STANDARD 17)

# Set the path to SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(SFML_INCLUDE_DIR "C:/SFML/include")
set(SFML_LIBRARY_DIR "C:/SFML/lib")
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
# Find SFML
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Add your executable
add_executable(${PROJECT_NAME} main.cpp)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
