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

	template class cuMemory<double>;
	template class cuMemory<complex<double>>;


	template void transferToDevice(cuMemory<d>&, const hostMemory<d>&);
	template void transferToDevice(cuMemory<cd>&, const hostMemory<cd>&);
	template void transferToHost(hostMemory<d>&, const cuMemory<d>&);
	template void transferToHost(hostMemory<cd>&, const cuMemory<cd>&);


}
