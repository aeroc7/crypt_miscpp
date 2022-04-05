set(DEP_GBENCHMARK_VERSION "1.6.1")
set(DEP_GBENCHMARK_LOC "https://github.com/google/benchmark/archive/refs/tags/v1.6.1.zip")

include(ExternalProject)
ExternalProject_Add(gbenchmark-build
    URL                 ${DEP_GBENCHMARK_LOC}
    CMAKE_ARGS          -G "Unix Makefiles"
                        -DBENCHMARK_DOWNLOAD_DEPENDENCIES=FALSE
                        -DBENCHMARK_ENABLE_GTEST_TESTS=OFF
                        -DCMAKE_BUILD_TYPE=Release
                        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                        -DBENCHMARK_ENABLE_LTO=TRUE
                        -DCMAKE_INSTALL_LIBDIR=lib
    BUILD_BYPRODUCTS    <INSTALL_DIR>/lib/libbenchmark.a
)

ExternalProject_Get_Property(gbenchmark-build INSTALL_DIR)

file(MAKE_DIRECTORY ${INSTALL_DIR}/include)
add_library(gbenchmark STATIC IMPORTED GLOBAL)
set_target_properties(gbenchmark
    PROPERTIES
        IMPORTED_LOCATION ${INSTALL_DIR}/lib/libbenchmark.a
        INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
        VERSION ${DEP_GBENCHMARK_VERSION}
)

add_dependencies(gbenchmark gbenchmark-build)
