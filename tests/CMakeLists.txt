


include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
	memory_test
	cuda_test.cpp
)

target_include_directories(
	memory_test
	PUBLIC
	${BLAS_DIRECTORIES}
	${CUDA_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/src/
)

target_link_libraries(
	memory_test
	gtest_main
	polymorphicMemory
	-lblaspp
	${CUDA_LIBRARIES}
)

#target_link_options(polymorphicMemory PUBLIC ${CUDA_LIBRARIES})
target_link_options(polymorphicMemory PUBLIC ${CUDA_FLAGS})

include(GoogleTest)

gtest_discover_tests(memory_test)

