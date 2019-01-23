find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

set(NDTT_IMPL_SOURCES
        impl/window.cpp)

set(NDTT_SOURCES
        main.cpp main_window.cpp titlebar.cpp)

add_executable(ndtt ${NDTT_SOURCES} ${NDTT_IMPL_SOURCES})

target_link_libraries(ndtt dtt ${CURSES_LIBRARIES})