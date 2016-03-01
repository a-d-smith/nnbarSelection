#ifndef LARLITE_HIDETRUTH_CXX
#define LARLITE_HIDETRUTH_CXX

#include "hideTruth.h"

namespace larlite {

	bool hideTruth::initialize() {

		return true;
	}
	
	bool hideTruth::analyze(storage_manager* storage) {
		partList P(storage);

		for (anaPart &part : P.List()){
			part.PrintAll(true);
		}

		std::cout << "=====================================" << std::endl;
		return true;
	}

	bool hideTruth::finalize() {
	
		return true;
	}

}
#endif
