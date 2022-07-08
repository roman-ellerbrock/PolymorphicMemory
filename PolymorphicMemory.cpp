//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "PolymorphicMemory.hpp"
#include <string.h>

namespace polymorphic {

	template
	class memory<complex<double>, CPU>;

	template
	class memory<double, CPU>;
}
