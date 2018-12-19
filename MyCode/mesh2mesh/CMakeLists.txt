## CMake specification for src directory
set(SOURCES config.h
    tables.h            IsoStuffer.hpp
    OctTree.h           OctTree.cpp
    DistValProc.h       DistValProc.cpp)

# utils/
set(UTILS_SRC
    ${INCLUDE_DIR1}/utils/macros.h     ${INCLUDE_DIR1}/utils/math.hpp)

# linearalgebra
set(LINEAR_SRC
    ${INCLUDE_DIR1}/linearalgebra/eig3.h    ${INCLUDE_DIR1}/linearalgebra/eig3.cpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INCLUDE_DIR1}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
    # =========================================================================
add_library(mesh2meshFunction
    ${INCLUDE_DIR1}/io/TglMeshReader.hpp    ${INCLUDE_DIR1}/io/TglMeshReader.cpp
    ${INCLUDE_DIR1}/generic/precision_type.hpp
    ${INCLUDE_DIR1}/generic/precision_type.cpp
    mesh2mesh.cpp
    ${SOURCES}              ${UTILS_SRC}            ${LINEAR_SRC})

target_link_libraries(mesh2meshFunction ${ICC_LIBS}        
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
)


