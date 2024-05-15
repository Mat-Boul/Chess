cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
include_directories(${SFML_DIR})
find_package(SFML COMPONENTS window system graphics REQUIRED)
add_executable(Chess main.cpp
        Bitboard.cpp
        Bitboard.h
        ChessGame.cpp
        ChessGame.h
        GUI.cpp
        GUI.h
)
target_link_libraries(Chess sfml-window sfml-system sfml-graphics)
