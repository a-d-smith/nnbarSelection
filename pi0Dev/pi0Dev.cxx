#ifndef LARLITE_PI0DEV_CXX
#define LARLITE_PI0DEV_CXX

#include "pi0Dev.h"
#include "math.h"

namespace larlite {

  bool pi0Dev::initialize() {
		nt = new TNtuple("data", "data", "M");
    return true;
  }
  
  bool pi0Dev::analyze(storage_manager* storage) {
 		partList P(storage);

		// Search for photons
		for (anaPart &part1 : P.List()){
			for (anaPart &part2 : P.List()){
				// Remove double counting
				if (part1.ID(true) > part2.ID(true)){
					// Both must be photons
					if (part1.PDG(true) == 22 && part2.PDG(true) == 22){
						// Both must have the same parent
						if (part1.ParentID(true) == part2.ParentID(true)){
							// This parent must be a pi0
							if (part1.ParentPDG(true) == 111 && part2.ParentPDG(true) == 111){
								// These photons came from a pi0!
								// Calculate their invariant mass
								double cosTheta = (1 / (part1.Momentum(true).Mag()*part2.Momentum(true).Mag()))*part1.Momentum(true).Dot(part2.Momentum(true));
								double M = std::pow(2 * part1.Energy(true) * part2.Energy(true) * (1 - cosTheta), 0.5);
								nt->Fill(M);
							}
						}
					}
				}
			}
		}
 
    return true;
  }

  bool pi0Dev::finalize() {
		nt->Write();
    return true;
  }

}
#endif
