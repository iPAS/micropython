# Create an INTERFACE library for our C module.
add_library(usermod_st7789 INTERFACE)

# Add our source files to the lib
target_sources(usermod_st7789 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/st7789.c
    ${CMAKE_CURRENT_LIST_DIR}/dw_font.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_supermarket_regular20.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_supermarket_regular40.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_supermarket_regular60.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_supermarket_regular120.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular20.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular40.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular60.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular80.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular120.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/font_th_sarabun_new_regular200.c)

# Add the current directory as an include directory.
target_include_directories(usermod_st7789 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR})

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE usermod_st7789)
