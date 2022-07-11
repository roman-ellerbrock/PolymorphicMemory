cmake_minimum_required(VERSION 3.0)

project(polymorphicmemory LANGUAGES C CXX CUDA)

#set(CUDA_PROPAGATE_HOST_FLAGS OFF)

#include(cmake/FindBLASPP.cmake)

add_subdirectory("src")

add_executable(memory
	src/main.cpp
)

#target_link_libraries(memory polymorphicMemory ${CUDA_LIBRARIES} -lcublas -lcurand)
target_link_libraries(memory 
	polymorphicMemory 
	-lblaspp
	${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} 
	${CUDA_LIBRARIES} -lcublas -lcurand
)

#set_target_properties(memory PROPERTIES CUDA_SEPARABLE_COMPILATION ON)


add_subdirectory("tests")

