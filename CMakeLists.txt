cmake_minimum_required(VERSION 3.0)

project(polymorphicmemory LANGUAGES C CXX CUDA)

#set(CUDA_PROPAGATE_HOST_FLAGS OFF)

add_executable(memory
	main.cpp
	PolymorphicMemory.cpp
	malloc.cu
)

target_link_libraries(memory  ${CUDA_LIBRARIES} -lcublas -lcurand)

#set_target_properties(memory PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
