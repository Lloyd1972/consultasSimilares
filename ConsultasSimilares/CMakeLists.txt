cmake_minimum_required(VERSION 3.5)

project(ConsultasSimilares VERSION 1.0 LANGUAGES CXX)

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
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ConsultasSimilares
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        address.cpp address.h consultation.cpp consultation.h consultationdialog.cpp consultationdialog.h consultationdialog.ui consultationfile.cpp consultationfile.h diagnosis.cpp diagnosis.h diagnosisdialog.cpp diagnosisdialog.h diagnosisdialog.ui diagnosisfile.cpp diagnosisfile.h doctor.cpp doctor.h doctordialog.cpp doctordialog.h doctordialog.ui doctorfile.cpp doctorfile.h icons.qrc medicine.cpp medicine.h medicinedialog.cpp medicinedialog.h medicinedialog.ui medicinefile.cpp medicinefile.h name.cpp name.h patient.cpp patient.h patientdialog.cpp patientdialog.h patientdialog.ui patientfile.cpp patientfile.h  tabledialog.h tabledialog.ui tuple.h
        dataEntryDialog.h
        dataEntryFile.h
        searchdialog.h searchdialog.cpp searchdialog.ui
        compresseddata.h compresseddata.cpp
        logo.ico
        app.o
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ConsultasSimilares APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ConsultasSimilares SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ConsultasSimilares
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ConsultasSimilares PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ConsultasSimilares)
endif()
set_target_properties(ConsultasSimilares PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ConsultasSimilares
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ConsultasSimilares)
endif()

# Copia el icono al directorio de salida
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/logo.ico ${CMAKE_CURRENT_BINARY_DIR}/logo.ico COPYONLY)

# Configura la aplicación para usar el icono (solo para Windows)
if(WIN32)
    set(CMAKE_RC_FLAGS "${CMAKE_RC_FLAGS} -i ${CMAKE_CURRENT_BINARY_DIR}/logo.ico")
endif()
