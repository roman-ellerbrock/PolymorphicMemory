
execute_process(COMMAND git submodule update --init -- external/blaspp)

#execute_process(COMMAND cd ${CMAKE_SOURCE_DIR}/external/blaspp && mkdir -fp build)
#execute_process(COMMAND cmake .. && make)
#execute_process(COMMAND cd ../../../)
#add_subdirectory(external/blaspp)

# Set up BLAS / LAPACK
# BLAS++ & LAPACK++ per default install to /opt/slate/lib, thus added a hint
find_library(BLAS_LIBRARIES
	NAMES blaspp
	HINTS /opt/slate/lib ./external/blaspp 
	)
message("BLAS++ libraries: ${BLAS_LIBRARIES}")
#	HINTS /opt/slate/lib ./external/blaspp ~ellerbr/code/blaspp/lib
#find_library(LAPACK_LIBRARIES
#	NAMES lapackpp
#	HINTS /opt/slate/lib 
#	REQUIRED)
#message("LAPACK++ libraries: ${LAPACK_LIBRARIES}")

