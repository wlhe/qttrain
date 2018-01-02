cmake_minimum_required(VERSION 2.8)

project(main)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_cpp(MAINWINDOW_MOC mainwindow.h)
qt5_wrap_ui(MAINWINDOW_UI mainwindow.ui)

message(STATUS "MAINWINDOW_MOC ${MAINWINDOW_MOC}")
message(STATUS "MAINWINDOW_UI ${MAINWINDOW_UI}")

set(sources 
    main.cpp
    mainwindow.cpp
    # ${MAINWINDOW_MOC} 
    # no need add moc source multiple, 
    # CMAKE_AUTOMOC will add moc cpp to source automatically
)

set(headers
    mainwindow.h
    # ${MAINWINDOW_UI}
    # CMAKE_AUTOUIC will add ui to header automatically
)

message(STATUS "sources ${sources}")
message(STATUS "headers ${headers}")

add_executable(${CMAKE_PROJECT_NAME} ${headers} ${sources} )

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)
