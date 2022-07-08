cmake_minimum_required(VERSION 3.0)

project(polymorphicmemory LANGUAGES C CXX CUDA)

#set(CUDA_PROPAGATE_HOST_FLAGS OFF)

#include(FindBLASPP.cmake)

add_executable(memory
	main.cpp
	PolymorphicMemory.cpp
	#	PolymorphicMemory.cu
	malloc.cu
)

target_link_libraries(memory ${CUDA_LIBRARIES} -lcublas -lcurand)
#target_link_libraries(memory ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} ${CUDA_LIBRARIES} -lcublas -lcurand)

#set_target_properties(memory PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
