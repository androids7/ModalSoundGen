find_package(MKL REQUIRED)
set(MKL_LIBS ${IOMP5_LIBRARY} ${MKL_LIBRARY_RT} ${MKL_LIBRARY_THREAD}  ${MKL_LIBRARY_ILP64} ${MKL_LIBRARY} ${OPENMP_LIB})
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
find_package(TBB REQUIRED)
include_directories(
	${MKL_INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${Boost_INCLUDE_DIRS}
)

AUX_SOURCE_DIRECTORY(. TTOM_SRCS)
ADD_LIBRARY(tet2matricesFunction
	${TTOM_SRCS}
	${INCLUDE_DIR2}/deformable/stvk.cpp
    	${INCLUDE_DIR2}/generic/precision_type.cpp
)
TARGET_LINK_LIBRARIES(
	tet2matricesFunction
	${CMAKE_THREAD_LIBS_INIT}
	${MKL_LIBS}
	${Boost_LIBRARIES}
	tbb
)
