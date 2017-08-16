project(common)

configure_file( version.h.in "${CMAKE_CURRENT_BINARY_DIR}/version.h" )

set(common_SOURCES
    utility.cpp
)

add_library(common STATIC ${common_SOURCES})

find_package(Qt5Core REQUIRED)

if (APPLE)
    find_library(FOUNDATION_LIBRARY NAMES Foundation)
    find_library(CORESERVICES_LIBRARY NAMES CoreServices)
    target_link_libraries(common ${FOUNDATION_LIBRARY} ${CORESERVICES_LIBRARY})
endif()

qt5_use_modules(common Core)
