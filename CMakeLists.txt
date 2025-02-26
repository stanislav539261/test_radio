cmake_minimum_required(VERSION 3.31)

project(test_radio VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES "src/*.cpp")

add_subdirectory(external/json)
add_executable(${PROJECT_NAME} ${IMGUI_SOURCE_FILES} ${SOURCE_FILES})

# Link system-wide libraries
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
