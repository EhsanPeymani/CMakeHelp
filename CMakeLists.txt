cmake_minimum_required(VERSION 3.10)

# set(PROJECT_NAME "Project1")

# set the project name
project(Project1 VERSION 1.4)

# IMPORTANT: definition of the option param comes in configure_file
# therefore it must be before configure_file
option(USE_OPTIONAL_LIB "Use optional libraries" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(ProjectConfig.h.in ProjectConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MathFunctions library
add_subdirectory(src/MathFunctions)

if (USE_OPTIONAL_LIB)
    add_subdirectory(src/OptionalFunctions)
    list(APPEND EXTRA_LIBS OptionalFunctions)
endif()

# add the executable
add_executable(test1 src/test1.cpp)
target_link_libraries(test1 PUBLIC MathFunctions)
target_link_libraries(test1 PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find ProjectConfig.h
target_include_directories(test1 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            )

install(TARGETS test1 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/ProjectConfig.h" DESTINATION include)

message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX "/home/ehsan/Documents/Ehsan/installdir")

include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Project1_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Project1_VERSION_MINOR}")
include(CPack)

# to create installer: 
# cpack
# cpack -G ZIP -C Debug

# to create source distribution
#cpack --config CPackSourceConfig.cmake
