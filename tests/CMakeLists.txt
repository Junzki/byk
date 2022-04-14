

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(${PROJECT_NAME}_SOURCE "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE ${PROJECT_NAME}_FILES "${${PROJECT_NAME}_SOURCE}/*.cpp")


set(PROJECT_LIBRARY_NAME "lib${PROJECT_NAME}")
add_library(${PROJECT_LIBRARY_NAME} STATIC ${${PROJECT_NAME}_FILES})

enable_testing()

add_executable(
        test_byk
        test_byk.cpp
)
target_link_libraries(
        test_byk
        gtest_main
        ${PROJECT_LIBRARY_NAME}
        ${LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(test_byk)
