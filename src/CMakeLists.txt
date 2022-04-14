

set(TARGET_BINARY "byk")
add_executable(${TARGET_BINARY} main.cpp byk.cpp db.cpp)

target_link_libraries(${TARGET_BINARY} ${LIBRARIES})