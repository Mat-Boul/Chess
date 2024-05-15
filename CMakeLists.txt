cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp
        Bitboard.cpp
        Bitboard.h
        ChessGame.cpp
        ChessGame.h
        GUI.cpp
        GUI.h
)
