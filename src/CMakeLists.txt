

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

target_include_directories(polymorphicMemory
	PUBLIC
	${BLAS_DIRECTORIES}
	${CUDA_INCLUDE_DIRS}
)

#target_link_options(polymorphicMemory PUBLIC ${CUDA_FLAGS})

target_link_libraries(polymorphicMemory 
	-lblaspp
	${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} 
)

