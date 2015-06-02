CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Project Name
PROJECT (testsdl)

# Define a variável VERSION que podemos usar com o cmake
SET(VERSION 0.1)

# Vamos usar o padrão mais novo do C++ (nullptr)
SET (CMAKE_CXX_FLAGS "-Wall -std=c++11")

# xxxxxxxxxx Find SDL2 library xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
# For this we will use pkg-config
INCLUDE(FindPkgConfig)
# Install libsdl2-dev in Ubuntu for this to work
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
# INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


# Add an excutable file
ADD_EXECUTABLE(tetris "main.cpp" )

# Link the executable with the SDL2 library
target_link_libraries(tetris ${SDL2_LIBRARIES})
