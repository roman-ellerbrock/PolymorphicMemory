

add_library(polymorphicMemory SHARED
	hostMemory.cpp	
	hostMemory.h
	cuMemory.h
	cuMemory.cu
#	PolymorphicMemory.hpp
#	PolymorphicMemory.cu
#	PolymorphicMemory.cuh
	malloc.cu
)
