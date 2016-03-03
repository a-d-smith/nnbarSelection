/**
 * \file pi0Dev.h
 *
 * \ingroup pi0Dev
 * 
 * \brief Class def header for a class pi0Dev
 *
 * @author rsjones
 */

/** \addtogroup pi0Dev

    @{*/

#ifndef LARLITE_PI0DEV_H
#define LARLITE_PI0DEV_H

#include "TNtuple.h"
#include "Analysis/ana_base.h"
#include "../hideTruth/anaPart.h"

namespace larlite {
  /**
     \class pi0Dev
     User custom analysis class made by SHELL_USER_NAME
   */
  class pi0Dev : public ana_base{
  
  public:

    /// Default constructor
    pi0Dev(){ _name="pi0Dev"; _fout=0;}

    /// Default destructor
    virtual ~pi0Dev(){}

    /** IMPLEMENT in pi0Dev.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in pi0Dev.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in pi0Dev.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

		TNtuple *nt;

  protected:
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
