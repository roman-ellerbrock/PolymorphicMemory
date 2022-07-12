



#####################################################################
# CUDA support
#####################################################################

option (CUDA_FEATS "Set to On to use CUDA features" ON)

if (CUDA_FEATS)
	message("CUDA compilation enabled.")

	enable_language(CUDA)
	find_package(CUDA REQUIRED)

	# Set CUDA_ARCHITECTURES
	cmake_policy(SET "CMP0104" NEW)
	if(NOT DEFINED ${CMAKE_CUDA_ARCHITECTURES})
		set(CMAKE_CUDA_ARCHITECTURES 52 61 75)
	endif()


	find_library(cublas
	NAMES cublas
	HINTS /usr/local/cuda/lib64
	REQUIRED)

	find_library(cudart
	NAMES libcudart.so.11.0
	HINTS /usr/local/cuda/lib64
	REQUIRED)


	find_library(curand
	NAMES curand
	HINTS /usr/local/cuda/lib64
	REQUIRED)

	#	set(CUDA_FLAGS "${CUBLAS} ${CURAND} ${CUDART}")
	#set(CUDA_FLAGS "${CUDA_LIBRARIES} -cublas -curand")
	#	set(CUDA_FLAGS "${CUDA_LIBRARIES} cublas curand")

	separate_arguments(CUDA_FLAGS UNIX_COMMAND "${CUDA_FLAGS}")



	message("CUDA_LIBRARIES: ${CUDA_LIBRARIES}")
	message("CUDA Flags: ${CUDA_FLAGS}")
	message("CUDA Include directories: ${CUDA_INCLUDE_DIRS}")

endif()




