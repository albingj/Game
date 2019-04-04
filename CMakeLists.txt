cmake_minimum_required(VERSION 3.13)
project(Game)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})




add_executable(
        Game
        main.cpp
        SDLcar.cpp SDLcar.h
        AFactory.cpp AFactory.h
        SDLFactory.cpp SDLFactory.h
        Game.cpp Game.h
        SDLFactory.cpp SDLFactory.h
        Car.cpp Car.cpp Car.h LTexture.cpp LTexture.h)

target_link_libraries(Game ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)
