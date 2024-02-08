cmake_minimum_required(VERSION 3.15...3.25)

project(Topdown
  VERSION
    1.0
  DESCRIPTION
    "Simple 2D Topdown Shooty"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(lib/bgfx.cmake)
# add_subdirectory(lib/sfml)
# add_subdirectory(lib/stduuid)
add_subdirectory(src)

# include(FetchContent)
# FetchContent_Declare(SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x)
# FetchContent_MakeAvailable(SFML)


target_link_libraries(topdown)