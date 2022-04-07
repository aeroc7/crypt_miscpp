cmake_minimum_required(VERSION 3.17)

project(crypto_miscpp CXX)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

# Compiler warnings
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Sanitizers
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# Static analysis
include(cmake/StaticAnalyzers.cmake)

# Testing
option(ENABLE_TESTING "Build and run tests" ON)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(3rdparty)
add_subdirectory(src)

if(ENABLE_TESTING)
    add_subdirectory(tests)
endif()
