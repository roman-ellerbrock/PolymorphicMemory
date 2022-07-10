//
// Created by Roman Ellerbrock on 6/30/22.
//

#ifndef POLYMORPHICMEMORY_H
#define POLYMORPHICMEMORY_H
#include "stdafx.h"
#include <vector>

namespace polymorphic {

	template <typename T>
	using hostMemory = std::vector<T>;

	std::ostream& operator<<(std::ostream& os, hostMemory<double>& mem);

}


#endif //POLYMORPHICMEMORY_H
