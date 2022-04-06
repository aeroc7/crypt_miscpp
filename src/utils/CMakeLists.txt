add_library(utilities INTERFACE)
set_target_properties(utilities
    PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/../
)