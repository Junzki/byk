cmake_minimum_required(VERSION 3.8)
project(byk CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

find_package(SQLite3 REQUIRED)
if (!${SQLite3_FOUND})
    EXIT(1)
endif()

include_directories(${SQLite3_INCLUDE_DIR})
SET(LIBRARIES ${SQLite3_LIBRARIES})


add_subdirectory(src)
add_subdirectory(tests)
