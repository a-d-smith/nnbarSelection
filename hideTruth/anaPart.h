#ifndef ANAPART_H
#define ANAPART_H

#include "Analysis/ana_base.h"
#include "DataFormat/mctrack.h"
#include "DataFormat/mcshower.h"
#include <iostream>
#include <utility>
#include <vector>
#include "string.h"
#include <sstream>

class anaPart{
friend class partList;
public:
	// Default Constructor
	anaPart(){};

	// Constructor (for tracks)
	anaPart(const larlite::mctrack &_mct);

	// Constructor (for showers)
	anaPart(const larlite::mcshower &_mcs);

	// Default Destructor
	~anaPart(){};

	// Getters
	unsigned int ID(bool _fullInfo);
	int          PDG(bool _fullInfo);
	char         Type(bool _fullInfo);

	TVector3     Start(bool _fullInfo);
	TVector3     End(bool _fullInfo);
	TVector3     Momentum(bool _fullInfo);
	double       Energy(bool _fullInfo);

	bool         Primary(bool _fullInfo);
	unsigned int ParentID(bool _fullInfo);
	int          ParentPDG(bool _fullInfo);
	anaPart*     Parent(bool _fullInfo);


	// Setters (can only change restricted info)
	void SetPDG(int __PDG);
	void SetType(char __Type);

	void SetStart(TVector3 __Start);
	void SetEnd(TVector3 __End);
	void SetMomentum(TVector3 __Momentum);
	void SetEnergy(double __Energy);

	void SetPrimary(bool __Primary);
	void SetParentID(unsigned int __ParentID);
	void SetParentPDG(int __ParentPDG);
	void SetParent(anaPart *__Parent);

	// Functions to print TVector3 objects nicely
	std::string PrintStart(bool _fullInfo);
	std::string PrintEnd(bool _fullInfo);
	std::string PrintMomentum(bool _fullInfo);

	// Function to print all information nicely
	void   PrintAll(bool _fullInfo);

protected:
	// We have two copies of the information you can hold on a particle.
	// The first copy, labeled by true, is the full information using truth.
	// The second, labeled by false, is the restricted information that would
	// be accessible in real data.

	std::pair<unsigned int, unsigned int> _ID;
	std::pair<int, int>                   _PDG;
	std::pair<char, char>                 _Type;

	std::pair<TVector3, TVector3>         _Start;
	std::pair<TVector3, TVector3>         _End;
	std::pair<TVector3, TVector3>         _Momentum;
	std::pair<double, double>             _Energy;

	std::pair<bool, bool>                 _Primary;
	std::pair<unsigned int, unsigned int> _ParentID;
	std::pair<int, int>                   _ParentPDG;
	std::pair<anaPart*, anaPart*>         _Parent;
};

// Constructor for MCTracks
inline anaPart::anaPart(const larlite::mctrack &_mct){
	_ID.first            = _mct.TrackID();
	_PDG.first           = _mct.PdgCode();
	_Type.first          = 't';
	
	_Start.first         = TVector3(_mct.Start().X(), _mct.Start().Y(), _mct.Start().Z());
	_End.first           = TVector3(_mct.End().X(), _mct.End().Y(), _mct.End().Z());
	_Momentum.first      = TVector3(_mct.Start().Px(), _mct.Start().Py(), _mct.Start().Pz());
	_Energy.first        = _mct.Start().E();

	_Primary.first       = (_mct.TrackID() == _mct.MotherTrackID());
	
	if (_Primary.first){
		_ParentID.first      = 2147483647; // No parent
		_ParentPDG.first     = 2147483647; // No parent PDG
	}
	else{
		_ParentID.first      = _mct.MotherTrackID();
		_ParentPDG.first     = _mct.MotherPdgCode();
	}

	// Restricted info on tracks 
	_ID.second           = _mct.TrackID();
	_Type.second         = 't';
	
	_Start.second        = TVector3(_mct.Start().X(), _mct.Start().Y(), _mct.Start().Z());
	_End.second          = TVector3(_mct.End().X(), _mct.End().Y(), _mct.End().Z());
	_Momentum.second     = TVector3(_mct.Start().Px(), _mct.Start().Py(), _mct.Start().Pz());
	//_Energy.second       = _mct.Start().E();

}

// Constructor for MCShowers
inline anaPart::anaPart(const larlite::mcshower &_mcs){
	_ID.first            = _mcs.TrackID();
	_PDG.first           = _mcs.PdgCode();
	_Type.first          = 's';
	
	_Start.first         = TVector3(_mcs.Start().X(), _mcs.Start().Y(), _mcs.Start().Z());
	_End.first           = TVector3(_mcs.End().X(), _mcs.End().Y(), _mcs.End().Z());
	_Momentum.first      = TVector3(_mcs.Start().Px(), _mcs.Start().Py(), _mcs.Start().Pz());
	_Energy.first        = _mcs.Start().E();

	_Primary.first       = (_mcs.TrackID() == _mcs.MotherTrackID());
	
	if (_Primary.first){
		_ParentID.first      = 2147483647; // No parent
		_ParentPDG.first     = 2147483647; // No parent PDG
	}
	else{
		_ParentID.first      = _mcs.MotherTrackID();
		_ParentPDG.first     = _mcs.MotherPdgCode();
	}

	// Restricted info on showers
	_ID.second           = _mcs.TrackID();
	_PDG.second          = _mcs.PdgCode();
	_Type.second         = 's';
	
	_Start.second        = TVector3(_mcs.Start().X(), _mcs.Start().Y(), _mcs.Start().Z());
	_End.second          = TVector3(_mcs.End().X(), _mcs.End().Y(), _mcs.End().Z());
	_Momentum.second     = TVector3(_mcs.Start().Px(), _mcs.Start().Py(), _mcs.Start().Pz());
	//_Energy.second       = _mcs.Start().E();

}

// Getters
inline unsigned int anaPart::ID(bool _fullInfo){
	if (_fullInfo){
		return (_ID.first);
	}
	else{
		return (_ID.second);
	}
}


inline int anaPart::PDG(bool _fullInfo){
	if (_fullInfo){
		return (_PDG.first);
	}
	else{
		return (_PDG.second);
	}
}


inline char anaPart::Type(bool _fullInfo){
	if (_fullInfo){
		return (_Type.first);
	}
	else{
		return (_Type.second);
	}
}


inline TVector3 anaPart::Start(bool _fullInfo){
	if (_fullInfo){
		return (_Start.first);
	}
	else{
		return (_Start.second);
	}
}


inline TVector3 anaPart::End(bool _fullInfo){
	if (_fullInfo){
		return (_End.first);
	}
	else{
		return (_End.second);
	}
}


inline TVector3 anaPart::Momentum(bool _fullInfo){
	if (_fullInfo){
		return (_Momentum.first);
	}
	else{
		return (_Momentum.second);
	}
}


inline double anaPart::Energy(bool _fullInfo){
	if (_fullInfo){
		return (_Energy.first);
	}
	else{
		return (_Energy.second);
	}
}


inline bool anaPart::Primary(bool _fullInfo){
	if (_fullInfo){
		return (_Primary.first);
	}
	else{
		return (_Primary.second);
	}
}


inline unsigned int anaPart::ParentID(bool _fullInfo){
	if (_fullInfo){
		return (_ParentID.first);
	}
	else{
		return (_ParentID.second);
	}
}


inline int anaPart::ParentPDG(bool _fullInfo){
	if (_fullInfo){
		return (_ParentPDG.first);
	}
	else{
		return (_ParentPDG.second);
	}
}


inline anaPart* anaPart::Parent(bool _fullInfo){
	if (_fullInfo){
		return (_Parent.first);
	}
	else{
		return (_Parent.second);
	}
}


// Setters
inline void anaPart::SetPDG(int __PDG){
	_PDG.second = __PDG;
}

inline void anaPart::SetType(char __Type){
	_Type.second = __Type;
}

inline void anaPart::SetStart(TVector3 __Start){
	_Start.second = __Start;
}

inline void anaPart::SetEnd(TVector3 __End){
	_End.second = __End;
}

inline void anaPart::SetMomentum(TVector3 __Momentum){
	_Momentum.second = __Momentum;
}

inline void anaPart::SetEnergy(double __Energy){
	_Energy.second = __Energy;
}

inline void anaPart::SetPrimary(bool __Primary){
	_Primary.second = __Primary;
}

inline void anaPart::SetParentID(unsigned int __ParentID){
	_ParentID.second = __ParentID;
}

inline void anaPart::SetParentPDG(int __ParentPDG){
	_ParentPDG.second = __ParentPDG;
}

inline void anaPart::SetParent(anaPart *__Parent){
	_Parent.second = __Parent;
}

// Functions to Print TVector3 objects nicely
inline std::string anaPart::PrintStart(bool _fullInfo){
	std::stringstream ss;
	if (_fullInfo){
		ss << "(" << _Start.first.X() << ", " << _Start.first.Y() << ", " <<  _Start.first.Z() << ")";
	}
	else{
		ss << "(" << _Start.second.X() << ", " << _Start.second.Y() << ", " <<  _Start.second.Z() << ")";
	}
	return ss.str();
}


inline std::string anaPart::PrintEnd(bool _fullInfo){
	std::stringstream ss;
	if (_fullInfo){
		ss << "(" << _End.first.X() << ", " << _End.first.Y() << ", " <<  _End.first.Z() << ")";
	}
	else{
		ss << "(" << _End.second.X() << ", " << _End.second.Y() << ", " <<  _End.second.Z() << ")";
	}
	return ss.str();
}


inline std::string anaPart::PrintMomentum(bool _fullInfo){
	std::stringstream ss;
	if (_fullInfo){
		ss << "(" << _Momentum.first.X() << ", " << _Momentum.first.Y() << ", " <<  _Momentum.first.Z() << ")";
	}
	else{
		ss << "(" << _Momentum.second.X() << ", " << _Momentum.second.Y() << ", " <<  _Momentum.second.Z() << ")";
	}
	return ss.str();
}


// Function to print all information nicely
inline void anaPart::PrintAll(bool _fullInfo){
	if (_fullInfo){
		std::cout << "Particle " << _ID.first << " (full info) -------------------------" << std::endl;
		std::cout << "  PDG       : " << _PDG.first;
		switch (_Type.first){
			case 's':
				std::cout << "  (shower)" << std::endl;
				break;
			case 't':
				std::cout << "  (track)" << std::endl;
				break;
			case 'i':
				std::cout << "  (invisible)" << std::endl;
				break;
			default:
				std::cout << std::endl;
		}
		std::cout << "  Start     : " << this->PrintStart(_fullInfo) << std::endl;
		std::cout << "  End       : " << this->PrintEnd(_fullInfo) << std::endl;
		std::cout << "  Momentum  : " << this->PrintMomentum(_fullInfo) << std::endl;
		std::cout << "  Energy    : " << _Energy.first << std::endl;
		if (_Primary.first){
			std::cout << "  Primary   : Yes" << std::endl;
		}
		else{
			std::cout << "  Primary   : No" << std::endl;
		}
		std::cout << "  ParentID  : " << _ParentID.first << std::endl;
		std::cout << "  ParentPDG : " << _ParentPDG.first << std::endl;
	}
	else{
		std::cout << "Particle " << _ID.second << " (restricted info) -------------------" << std::endl;
		std::cout << "  PDG       : " << _PDG.second;
		switch (_Type.second){
			case 's':
				std::cout << "  (shower)" << std::endl;
				break;
			case 't':
				std::cout << "  (track)" << std::endl;
				break;
			case 'i':
				std::cout << "  (invisible)" << std::endl;
				break;
			default:
				std::cout << std::endl;
		}
		std::cout << "  Start     : " << this->PrintStart(_fullInfo) << std::endl;
		std::cout << "  End       : " << this->PrintEnd(_fullInfo) << std::endl;
		std::cout << "  Momentum  : " << this->PrintMomentum(_fullInfo) << std::endl;
		std::cout << "  Energy    : " << _Energy.second << std::endl;
		if (_Primary.second){
			std::cout << "  Primary   : Yes" << std::endl;
		}
		else{
			std::cout << "  Primary   : No" << std::endl;
		}
		std::cout << "  ParentID  : " << _ParentID.second << std::endl;
		std::cout << "  ParentPDG : " << _ParentPDG.second << std::endl;
	}
}

// ----------------------------------------------------
// Here we define the list of particles within the file
//

class partList{
public:
	// Constructor taking LArLite storage manager
	partList(larlite::storage_manager *_storage);

	// Default Destructor
	~partList(){};

	// Function to add a particle to the list (and assign it an ID)
	void AddParticle(anaPart _part);

	// Function to see if a particle exists (by ID)
	bool ParticleExists(unsigned int __ID);

	// Function to find a particle by ID
	anaPart GetParticle(unsigned int __ID);

	// Function to return the particle list
	std::vector<anaPart> List();

protected:
	std::vector<anaPart> _partList;
};

inline partList::partList(larlite::storage_manager *_storage){
	auto ev_mct = _storage->get_data<larlite::event_mctrack>("mcreco");
	auto ev_mcs = _storage->get_data<larlite::event_mcshower>("mcreco");

	if (!ev_mct){
		std::cerr << "Error: Invalid MCTrack pointer" << std::endl;
		exit(1);
	}
	if (!ev_mcs){
		std::cerr << "Error: Invalid MCShower pointer" << std::endl;
		exit(1);
	}
	
	// Load in the tracks and showers as anaPart objects
	for (auto const &mct : *ev_mct){
		anaPart thisPart(mct);
		_partList.push_back(thisPart);
	}	
	for (auto const &mcs : *ev_mcs){
		anaPart thisPart(mcs);
		_partList.push_back(thisPart);
	}	

	// Find the parents (if they leave a track or shower!)
	for (anaPart &part1 : _partList){
		for (anaPart &part2 : _partList){
			if (part1.ParentID(true) == part2.ID(true)){
				part1._Parent.first = &part2;
			}
		}
	}
}

inline bool partList::ParticleExists(unsigned int __ID){
	for (anaPart &part : _partList){
		if (part.ID(true) == __ID){
			return true;
		}
	}
	return false;
}

inline anaPart partList::GetParticle(unsigned int __ID){
	if (this->ParticleExists(__ID)){
		for (anaPart &part : _partList){
			if (part.ID(true) == __ID){
				return part;
			}
		}
	}		
	std::cerr << "Error: No particle with ID " << __ID << " exists." << std::endl;
	exit(1);
	anaPart part;
	return part;	
}

inline std::vector<anaPart> partList::List(){
	return _partList;
}

#endif
