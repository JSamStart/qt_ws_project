cmake_minimum_required(VERSION 3.16)

project(workshop_test_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appworkshop_test_project
    main.cpp
    test_klasse.h
    test_klasse.cpp
    test_klasse_2.h
    test_klasse_2.cpp
)

qt_add_qml_module(appworkshop_test_project
    URI workshop_test_project
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appworkshop_test_project PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appworkshop_test_project
    PRIVATE Qt6::Quick)

install(TARGETS appworkshop_test_project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
