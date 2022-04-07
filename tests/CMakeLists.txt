include(GoogleTest)
macro(package_add_test TESTNAME)
    # create an executable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main function to
    # the test executable.
    target_link_libraries(${TESTNAME} project_options project_warnings gtest gtest_main gbenchmark main_crypto_source mbase64)
    
    gtest_discover_tests(${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        WORKING_DIRECTORY ${PROJECT_DIR}
    )
endmacro()

package_add_test(Base64Test base64_test.cpp)