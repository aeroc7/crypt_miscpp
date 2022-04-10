add_executable(base64 main.cpp)
add_library(base64_l base64.cpp)

set(base64_common project_options project_warnings utilities)

target_link_libraries(base64_l
    PRIVATE
        ${base64_common}
)

target_link_libraries(base64
    PRIVATE
        ${base64_common}
        base64_l
)

add_library(mbase64 STATIC IMPORTED GLOBAL)
set_target_properties(mbase64
    PROPERTIES
        IMPORTED_LOCATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libbase64_l.a
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}
)

add_dependencies(mbase64 base64_l)
