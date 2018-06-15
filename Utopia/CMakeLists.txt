# CMakeList.txt : CMake project for Utopia, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Utopia "main.cpp" "StatsCalculator.h" "StatsCalculator.cpp" "Constants.h" "Helpers.h")

# TODO: Add tests and install targets if needed.
