
include_directories(
    	${Boost_INCLUDE_DIR}
  	${CMAKE_INCLUDE_CURRENT_DIR}
	${INCLUDE_DIR2}
)
AUX_SOURCE_DIRECTORY(. SYN_SRCS)
add_library(
	synthesisFunction
	${SYN_SRCS}
	${INCLUDE_DIR2}/generic/precision_type.cpp
	${INCLUDE_DIR2}/generic/precision_type.hpp
)
TARGET_LINK_LIBRARIES( 
	synthesisFunction
	${MKL_LIBS}
	${Boost_FILESYSTEM_LIBRARY} 
	${Boost_SYSTEM_LIBRARY}
	${GSL_LIBRARIES}
)
