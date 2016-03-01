#ifndef LARLITE_HIDETRUTH_H
#define LARLITE_HIDETRUTH_H

#include "Analysis/ana_base.h"

namespace larlite {
	class hideTruth : public ana_base{
	
	public:

		/// Default constructor
		hideTruth(){ _name="hideTruth"; _fout=0;}

		/// Default destructor
		virtual ~hideTruth(){}

		virtual bool initialize();

		virtual bool analyze(storage_manager* storage);

		virtual bool finalize();

	protected:
		
	};
}





#endif

