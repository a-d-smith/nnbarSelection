#ifndef LARLITE_HIDETRUTH_CXX
#define LARLITE_HIDETRUTH_CXX

#include "hideTruth.h"

namespace larlite {

	bool hideTruth::initialize() {

		return true;
	}
	
	bool hideTruth::analyze(storage_manager* storage) {
		
		auto ev_mct = storage->get_data<event_mctrack>("mcreco");
		auto ev_mcs = storage->get_data<event_mcshower>("mcreco");

		if (!ev_mct){
			std::cerr << "MCTrack pointer is invalid" << std::endl;
			exit(1);
		}

		if (!ev_mcs){
			std::cerr << "MCShower pointer is invalid" << std::endl;
			exit(1);
		}

		return true;
	}

	bool hideTruth::finalize() {
	
		return true;
	}

}
#endif
