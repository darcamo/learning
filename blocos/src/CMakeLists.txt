cmake_minimum_required (VERSION 2.8)

# xxxxxxxxxx GLOB for all source files xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
# The library sources correspond to all cpp files, except blocos.cpp
file(
  GLOB
  LIBSOURCES
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  "*.cpp"
  )
list(REMOVE_ITEM LIBSOURCES "blocos.cpp")
# message(STATUS "Sources: ${LIBSOURCES}")
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

# xxxxxxxxxx Required Libraries xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
# Look up SDL and add the include directory to our include path
find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


add_library(libblocos STATIC ${LIBSOURCES})
add_executable(blocosexec "blocos.cpp")
target_link_libraries(blocosexec libblocos ${SDL_LIBRARY} "SDL_ttf")

# Set the output name of the blocos library and executable file
set_target_properties(libblocos
                      PROPERTIES OUTPUT_NAME
                      "blocos")
set_target_properties(blocosexec
                      PROPERTIES OUTPUT_NAME
                      "blocos")

# add_executable(blocos "blocos.cpp")
# target_link_libraries(blocos ${SDL_LIBRARY} "SDL_ttf")