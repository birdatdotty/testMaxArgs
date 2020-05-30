cmake_minimum_required(VERSION 3.5)

project(testMaxArgs LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON) -- у меня нет ui файлов
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON) -- у меня нет файла ресурсов

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(testMaxArgs
  main.cpp
)

target_link_libraries(testMaxArgs Qt5::Core)
