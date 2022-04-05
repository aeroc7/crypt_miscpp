add_executable(b64_encode main.cpp)

target_link_libraries(b64_encode
    PRIVATE
        project_options
        project_warnings
)