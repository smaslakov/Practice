cmake_minimum_required(VERSION 3.26)
project(newProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(newProject main.cpp
Card.cpp Card.h
GameControl.cpp GameControl.h
        Deck.cpp
        Player.cpp
        Field.cpp Field.h
)
