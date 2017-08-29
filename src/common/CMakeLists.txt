project(common)

configure_file( version.h.in "${CMAKE_CURRENT_BINARY_DIR}/version.h" )

set(common_SOURCES
    utility.cpp
)

add_library(common STATIC ${common_SOURCES})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Hack! Use the same file and macro name as csync so that when csync
# includes this library statically, it will use the "export" declspec
# rather than the "import".
generate_export_header( common
  EXPORT_MACRO_NAME OCSYNC_EXPORT
  EXPORT_FILE_NAME ocsynclib.h
)

find_package(Qt5Core REQUIRED)

if (APPLE)
    find_library(FOUNDATION_LIBRARY NAMES Foundation)
    find_library(CORESERVICES_LIBRARY NAMES CoreServices)
    target_link_libraries(common ${FOUNDATION_LIBRARY} ${CORESERVICES_LIBRARY})
endif()

qt5_use_modules(common Core)
