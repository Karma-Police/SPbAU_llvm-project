cmake_minimum_required(VERSION 2.8.8)
project(SteensgaardsAnalysis)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

if ( "${LLVM_PACKAGE_VERSION}" VERSION_LESS "3.8" )
    message(FATAL_ERROR "Need LLVM >=3.8")
endif()

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

#Without -fno-rtti nothing works. W T F 
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fno-rtti -fPIC -std=c++11")

message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# Handy macro to copy files matching a globbing pattern in the current source
# source directory to the current build directory
#------------------------------------------------------------------------------
macro(copy_files_to_build_dir GLOBS)
    file(GLOB ABSOLUTE_PATH_TO_FILES_TO_COPY ${ARGV})

    foreach(file ${ABSOLUTE_PATH_TO_FILES_TO_COPY})
        get_filename_component(filename ${file} NAME)
        configure_file(${filename} ${filename} COPYONLY)
    endforeach()
endmacro()



add_subdirectory("HelloWorld/lib")
add_subdirectory("AAHelloWorld/lib")

