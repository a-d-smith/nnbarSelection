#ifndef LARLITE_HIDETRUTH_CXX
#define LARLITE_HIDETRUTH_CXX

#include "hideTruth.h"

namespace larlite {

	bool hideTruth::initialize() {

		return true;
	}
	
	bool hideTruth::analyze(storage_manager* storage) {
		partList P(storage);

		anaPart newPart;
		TVector3 newStart(1,2,3);
		TVector3 newEnd(4,5,6);
		TVector3 newP(1,2,3);
		newPart.SetPDG(111);
		newPart.SetType('i');		
		newPart.SetStart(newStart);
		newPart.SetEnd(newEnd);
		newPart.SetMomentum(newP);
		newPart.SetEnergy(7.8);
		newPart.SetPrimary(true);

		if(P.ParticleExists(0)){
			anaPart parent = P.GetParticle(0);
			newPart.SetParent(&parent);
		}

		P.AddParticle(newPart);

		for (anaPart &part : P.List()){
			part.PrintAll(false);
		}
		

		std::cout << "=====================================" << std::endl;
		std::cin.get();

		return true;
	}

	bool hideTruth::finalize() {
	
		return true;
	}

}
#endif
