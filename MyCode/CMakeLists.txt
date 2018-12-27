project(modalsound)
cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(Boost 1.48 REQUIRED COMPONENTS
    "filesystem" "system" "program_options")

set(INCLUDE_DIR1 /home/jxt/ModalSoundGen/IsoStuffer/src)
set(INCLUDE_DIR2 /home/jxt/ModalSoundGen/ModalSound/src)


AUX_SOURCE_DIRECTORY(. DIR_SRCS)
add_subdirectory(mesh2mesh)
add_subdirectory(tet2matrices)
add_subdirectory(synthesis)
include_directories(
	${INCLUDE_DIR2}                                                                                      
)
ADD_EXECUTABLE(main ${DIR_SRCS})
target_link_libraries(main
	 mesh2meshFunction
	 tet2matricesFunction
	 synthesisFunction
)


