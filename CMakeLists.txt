cmake_minimum_required(VERSION 3.13)
project(Game)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})




add_executable(
        Game
        main.cpp
        cmake-build-debug/SDL/SDLcar.cpp cmake-build-debug/SDL/SDLcar.h
        AFactory.cpp AFactory.h
        cmake-build-debug/SDL/SDLFactory.cpp cmake-build-debug/SDL/SDLFactory.h
        Game.cpp Game.h
        cmake-build-debug/SDL/SDLFactory.cpp cmake-build-debug/SDL/SDLFactory.h
        Car.cpp Car.cpp Car.h cmake-build-debug/SDL/LTexture.cpp cmake-build-debug/SDL/LTexture.h cmake-build-debug/SDL/SDLinput.cpp cmake-build-debug/SDL/SDLinput.h Entity.cpp Entity.h Background.cpp Background.h cmake-build-debug/SDL/SDLBackground.cpp cmake-build-debug/SDL/SDLBackground.h Player.cpp Player.h cmake-build-debug/SDL/SDLPlayer.cpp cmake-build-debug/SDL/SDLPlayer.h Singleton.cpp Singleton.h cmake-build-debug/SDL/SDLTimer.cpp cmake-build-debug/SDL/SDLTimer.h Rocket.cpp Rocket.h cmake-build-debug/SDL/SDLRocket.cpp cmake-build-debug/SDL/SDLRocket.h DropedItem.cpp DropedItem.h cmake-build-debug/SDL/SDLDropedItem.cpp cmake-build-debug/SDL/SDLDropedItem.h cmake-build-debug/SDL/SDLText.cpp cmake-build-debug/SDL/SDLText.h)

target_link_libraries(Game ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf  )
