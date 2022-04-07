add_subdirectory(utils)
add_subdirectory(base64)

add_library(main_crypto_source INTERFACE)
set_target_properties(main_crypto_source
    PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/
)