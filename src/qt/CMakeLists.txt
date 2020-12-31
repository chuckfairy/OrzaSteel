# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(AUTOGEN_TARGET_DEPENDS ON)

# find the location of Qt header files and libraries
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Designer REQUIRED)


file(GLOB orzasteel.qt_UIS
	Window.ui
	Settings/Settings.ui
	Settings/PedalEditor.ui
	Settings/PedalEditArea.ui
	Settings/StringEditor.ui
	Settings/StringEditArea.ui
	Settings/SoundEditor.ui
	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src/*.ui"
)


# Resources

qt5_add_resources(RESOURCES ./Resources.qrc)


#links

#FIND_PACKAGE(Boost)
find_package( Boost 1.45.0 COMPONENTS filesystem regex )

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	../common

	"${ORZASTEEL_ROOT_PATH}"
	"${ORZASTEEL_ROOT_PATH}/src"
	"${ORZASTEEL_ROOT_PATH}/lib-src"

	"${ORZASTEEL_ROOT_PATH}/lib-src/liborza/src"
	"${ORZASTEEL_ROOT_PATH}/lib-src/liborza/lib-src"
	"${ORZASTEEL_ROOT_PATH}/lib-src/liborza-qt/src"
	"${ORZASTEEL_ROOT_PATH}/lib-src/liborza-qt/lib-src"

	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src"
	"${CMAKE_CURRENT_BINARY_DIR}/../../lib-src/inputwidgets/src"

	"${CMAKE_CURRENT_BINARY_DIR}/../../lib-src/liborza/src"
	"${CMAKE_CURRENT_BINARY_DIR}/../../lib-src/liborza-qt/src"

	${Boost_INCLUDE_DIR}
)


# Src code base, extended in CMakeFiles in each App

file(
	GLOB
	orzasteel.qt_SRC
	"${ORZASTEEL_ROOT_PATH}/lib-src/QtAwesome/*.cpp"
	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src/fileinputwidget.cpp"
	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src/ColorInput.cpp"
	Resource/*.cpp
	Instrument/*.cpp
	Midi/*.cpp
	Settings/*.cpp
	Widget/BackgroundImage.cpp
	Window.cpp
	main.cpp
	ui_Window.h
)


# Qt Objects / mocs

file( GLOB orzasteel.qt_moc_files
	"${ORZASTEEL_ROOT_PATH}/lib-src/QtAwesome/*.h"
	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src/fileinputwidget.h"
	"${ORZASTEEL_ROOT_PATH}/lib-src/inputwidgets/src/ColorInput.h"
	Window.h
	Widget/BackgroundImage.h
	Instrument/StringArea.h
	Instrument/Bridge.h
	Instrument/Neck.h
	Instrument/Tonebar.h
	Instrument/Module.h
	Instrument/PedalWrap.h
	Instrument/PedalArea.h
	Settings/StringEditor.h
	Settings/StringEditArea.h
	Settings/PedalEditor.h
	Settings/PedalEditArea.h
	Settings/SoundEditor.h
)


# CMake config apps

file(GLOB orzasteel.qt_SRC
	${orzasteel.qt_SRC}
	**/**/moc_*.cpp
)

qt5_wrap_ui(orzasteel.qt_UIS ${orzasteel.qt_UIS} )

qt5_wrap_cpp( MY_MOCED_FILES ${orzasteel.qt_moc_files} )


# Configure config headers

configure_file(Config/Config.h.in Config/Config.h)


# Main executable

add_executable(orzasteel.qt ${orzasteel.qt_SRC} ${RESOURCES} ${MY_MOCED_FILES} ${orzasteel.qt_UIS} )

target_link_libraries( orzasteel.qt
	PUBLIC
	dl
	jack
	liborza-common-jack
	liborza-qt
	liborza-common-plugin
	orzasteel-common
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	Qt5::Qml
	Qt5::Designer
	${Boost_LIBRARIES}
)

install( TARGETS
	orzasteel.qt

	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

#Desktop file
if (UNIX)
	install(FILES orzasteel.qt.desktop DESTINATION /usr/local/share/applications)
	install(FILES ../assets/orzasteel.png
		DESTINATION /usr/local/share/icons)
endif()
