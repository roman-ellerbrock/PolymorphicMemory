//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "cuMemory.hpp"
#include <cuda_runtime.h>
//#include <blas.hh>

namespace polymorphic {
//	blas::set_device( device );

	using d = double;
	using cd = complex<double>;

	template class cudaAllocator<double>;
	template class cudaAllocator<complex<double>>;

	template class cuMemory<double>;
	template class cuMemory<complex<double>>;
}


