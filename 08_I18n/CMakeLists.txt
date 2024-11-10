cmake_minimum_required(VERSION 3.10)
project(GameInternational)

find_package(Gettext REQUIRED)

set(PO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/po)
set(RU_PO_FILE ${PO_DIR}/ru/game.po)


gettext_process_po_files(ru ALL INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX} PO_FILES ${RU_PO_FILE})

add_executable(game src/game.c)

install(TARGETS game DESTINATION ${CMAKE_INSTALL_PREFIX})