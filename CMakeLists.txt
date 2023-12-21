cmake_minimum_required(VERSION 3.15...3.25)

project(Topdown
  VERSION
    1.0
  DESCRIPTION
    "Very nice project"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/bgfx.cmake)
add_subdirectory(lib/sfml)
# find_package(glfw3 3.3 REQUIRED)

set(C_SOURCES src/main.cpp src/Bullet.cpp src/Game.cpp src/input.cpp src/Player.cpp)
set(C_HEADERS src/Bullet.h src/Game.h src/input.h src/Player.h)

add_executable(main ${C_SOURCES} ${C_HEADERS})
target_link_libraries(main bgfx bx sfml-system sfml-window sfml-graphics)