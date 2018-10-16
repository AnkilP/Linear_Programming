cmake_minimum_required(VERSION 3.12)
project(Simplex)

set(c++ 14)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(Simplex main.cpp Simplex.h Dual_Primal.cpp Dual_Primal.h Simplex.cpp)

TARGET_LINK_LIBRARIES( Simplex LINK_PUBLIC ${Boost_LIBRARIES} )