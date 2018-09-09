# Common lib
project(orzasteel-common CXX)


# Main config
configure_file(Config/Config.h.in Config/Config.h)


# Modules
#add_subdirectory(Network)
#add_subdirectory(Phone)


#set( ORZASTEEL_GUI_INCLUDE_FILES )
file( GLOB
	ORZASTEEL_COMMON_INCLUDE_FILES
	"*.cpp"
	"*.h"
)


## Building
# create orzasteel-gui library
add_library( orzasteel-common SHARED ${ORZASTEEL_COMMON_INCLUDE_FILES} )

target_link_libraries( orzasteel-common )

target_include_directories( orzasteel-common PUBLIC )

set_target_properties(orzasteel-common PROPERTIES LINKER_LANGUAGE CXX)


## Installing
# add installation for target farweller

install( TARGETS
   orzasteel-common
   EXPORT orzasteel-common
   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
