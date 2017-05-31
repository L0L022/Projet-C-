cmake_minimum_required(VERSION 2.8.7)

project(Projet-C-)

add_definitions(-std=c++11)

include_directories(.)
file(
        GLOB_RECURSE
        SRC
        *.cpp
)

add_executable(app ${SRC})

find_package(X11)
if (X11_FOUND)
  include_directories(${X11_INCLUDE_DIRS})
  target_link_libraries(app ${X11_LIBRARIES})
endif (X11_FOUND)
