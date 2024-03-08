cmake_minimum_required(VERSION 3.5)
project(EthoCryp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    files/headers/menubar.h
    files/cpp/menubar.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/files/cpp
    ${PROJECT_SOURCE_DIR}/files/headers
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(EthoCryp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        files/cpp/statusbar.cpp
        files/headers/statusbar.h
        files/headers/fileslayout.h
        files/cpp/fileslayout.cpp
        files/headers/filessettingslayout.h
        files/cpp/filessettingslayout.cpp

    )
else()
    if(ANDROID)
        add_library(EthoCryp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(EthoCryp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(EthoCryp PRIVATE
    ${PROJECT_SOURCE_DIR}/files/cpp
    ${PROJECT_SOURCE_DIR}/files/headers
)

target_link_libraries(EthoCryp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.EthoCryp)
endif()
set_target_properties(EthoCryp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS EthoCryp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(EthoCryp)
endif()
