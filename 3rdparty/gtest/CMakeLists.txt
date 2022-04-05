set(DEP_GTEST_VERSION "1.11.0")
set(DEP_GTEST_LOC "https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip")

include(ExternalProject)
ExternalProject_Add(gtest-build
    URL                 ${DEP_GTEST_LOC}
    CMAKE_ARGS          -G "Unix Makefiles"
                        -DCMAKE_BUILD_TYPE=Release
                        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                        -DCMAKE_INSTALL_LIBDIR=lib
    BUILD_BYPRODUCTS    <INSTALL_DIR>/lib/libgtest.a
)

ExternalProject_Get_Property(gtest-build INSTALL_DIR)

file(MAKE_DIRECTORY ${INSTALL_DIR}/include)
add_library(gtest STATIC IMPORTED GLOBAL)
set_target_properties(gtest
    PROPERTIES
        IMPORTED_LOCATION ${INSTALL_DIR}/lib/libgtest.a
        INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
        VERSION ${DEP_GTEST_VERSION}
)

add_dependencies(gtest gtest-build)
