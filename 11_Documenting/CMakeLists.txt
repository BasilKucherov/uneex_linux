cmake_minimum_required(VERSION 3.10)
project(GameInternationalRoman VERSION 0.1.0)

find_package(Gettext REQUIRED)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
    configure_file(${CMAKE_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
else()
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif()

set(PO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/po)
set(RU_PO_FILE ${PO_DIR}/ru/game.po)


gettext_process_po_files(ru ALL INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX} PO_FILES ${RU_PO_FILE})

add_executable(game src/game.c src/romans.c)

install(TARGETS game DESTINATION ${CMAKE_INSTALL_PREFIX})