add_library(usermod_motor INTERFACE)

target_sources(usermod_motor INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/modmotor.c
)

target_include_directories(usermod_motor INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(usermod INTERFACE usermod_motor)
