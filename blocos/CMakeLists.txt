cmake_minimum_required (VERSION 2.8)
project (Blocos)

# The version number.
set (BLOCOS_VERSION_MAJOR 1)
set (BLOCOS_VERSION_MINOR 0)
set(BLOCOS_VERSION
  ${BLOCOS_VERSION_MAJOR}.${BLOCOS_VERSION_MINOR})


set(BLOCOS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(BLOCOS_ASSETS_DIR ${PROJECT_SOURCE_DIR}/assets)
set(BLOCOS_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)


# xxxxxxxxxx Create the config.h file xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
set(config_warning "THIS FILE WAS GENERATED AUTOMATICALLY. DON'T CHANGE IT MANUALLY.")
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${BLOCOS_SOURCE_DIR}/config.h"
  )
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


# Add the src directory (it has its own CMakeLists.txt file)
add_subdirectory(src)


# xxxxxxxxxx Install the executable file and the assets xxxxxxxxxxxxxxxxxxx
install(
  DIRECTORY assets/
  DESTINATION ${BLOCOS_BINARY_DIR}
)
install (
  FILES ${BLOCOS_SOURCE_DIR}/blocos
  PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
  DESTINATION ${BLOCOS_BINARY_DIR})
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx