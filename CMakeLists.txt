cmake_minimum_required(VERSION 3.15...3.25)

project(Topdown
  VERSION
    1.0
  DESCRIPTION
    "Simple 2D Topdown Shooty"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS FALSE)

# add_subdirectory(lib/bgfx.cmake)
add_subdirectory(lib/SFML)


# include(FetchContent)
# FetchContent_Declare(SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x)
# FetchContent_MakeAvailable(SFML)

# TODO: move into src/CMakeLists
set(C_SOURCES src/main.cpp src/Bullet.cpp src/Game.cpp src/Player.cpp src/Entity.cpp src/EntityManager.cpp src/PlayingEntity.cpp src/Enemy.cpp)
set(C_HEADERS src/Bullet.h src/Game.h  src/Player.h src/Entity.h src/EntityManager.h src/PlayingEntity.h src/Enemy.h)

add_executable(main ${C_SOURCES} ${C_HEADERS})

target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)
# target_link_libraries(topdown PRIVATE bgfx bx sfml-system sfml-window sfml-graphics)