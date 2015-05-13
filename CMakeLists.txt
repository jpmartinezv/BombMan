cmake_minimum_required(VERSION 2.8)
project(SDL2_App)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# includes cmake/FindSDL2.cmake cmake/FindSDL2_image.cmake cmake/FindSDL2_ttf.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Player.cpp src/Obstacle.cpp src/Map.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Assets
file(COPY ${PROJECT_SOURCE_DIR}/assets/monster.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(COPY ${PROJECT_SOURCE_DIR}/assets/bh.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(COPY ${PROJECT_SOURCE_DIR}/assets/beat.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)

add_executable(SDL2_App ${SOURCE_FILES})
target_link_libraries(SDL2_App ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY})
