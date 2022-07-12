###########################################################################
#
# --- Polymorphic Memory library ---
#
# Description:
# This library provides simple vector classes for host and device.
#
# Main author: Roman Ellerbrock
###########################################################################

#set(CMAKE_VERBOSE_MAKEFILE ON) # For debugging

cmake_minimum_required(VERSION 3.0)

project(polymorphicmemory LANGUAGES C CXX CUDA)

#set(CUDA_PROPAGATE_HOST_FLAGS OFF)

add_executable(memory
	src/main.cpp
)

# Include libs
include(cmake/FindBLASPP.cmake)
include(cmake/CUDA.cmake)

add_subdirectory("src")

target_link_libraries(memory 
	polymorphicMemory 
	-lblaspp
	${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} 
)

target_include_directories(memory
	PUBLIC
	${BLAS_DIRECTORIES}
)

#set_target_properties(memory PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_subdirectory("tests")

