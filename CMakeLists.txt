cmake_minimum_required(VERSION 3.5)

project(insurance_company LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(Qt5_DIR /Users/halin-george/Qt1/5.14.1/wasm_32/lib/cmake/Qt5)

if (ANDROID)
    add_library(insurance_company SHARED
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
            ${TS_FILES}
            )
else ()
    add_executable(insurance_company
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
            company.h
            company.cpp
            game.h
            game.cpp
            insurance.h
            insurance.cpp
            options.h
            options.cpp
            error.h
            base.h
            parse.h
            parse.cpp
            )
endif ()

target_link_libraries(insurance_company PRIVATE Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
