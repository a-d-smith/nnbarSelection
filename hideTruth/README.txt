                    The University of Manchester
                  School of Physics and Astronomy
---------------------------------------------------------------------
          Investigating DUNE's sensitivity to bound neutron-
                     antineutron oscillations.
---------------------------------------------------------------------
                   Rhiannon Jones & Andrew Smith
                          MPhys Project
                           2015 / 2016

=====================================================================

Repository : hideTruth

Within LArLite, there are two main types of data we will use: 

            truth-level  = things supplied from the generator of
                           the particle... eg. PDG codes, the 
                           heirarchy of the production of the 
                           particles, etc.

            perfect-reco = data which is similar to what you would 
                           expect to see in real experimental data.
                           eg. Energy of a shower (including effects
                           like shower leakage).

We can use one of two analysis units in which to do our analysis, an
"anaunit" or an "ERAna". In the first semester's work we used 
anaunits to access only truth-level data and ERAnas to access 
perfect-reco and truth-level data. Within an ERAna, we are made blind
to any information that would not be available in real data (such as 
PDG codes). This is an advantage as it stops us from writing 
algorithms that would not function on real data. But, we have found 
that within an ERAna, the truth-level information does not match that
in an anaunit and seems to be non-sensical. So, instead the aim is to
access truth and perfect-reco data within an anaunit and manually 
blind ourselves to information not available in real data.

This package contains code which organises particles into a single 
structure containing BOTH the blinded and the full information. We 
will perform our analyses on the blinded information and then use
the full information as a comparison to calculate the effectiveness
of a given algorithm.


=====================================================================

Class : anaPart

We define a class anaPart, which can describe any type of particle 
within the detector. An instance of this class can be used to access
both the full (truth-level + perfect-reco) information on the 
particle, and the restricted (mimicking real data) information.

Suppose "part" was an instance of anaPart, when accessing information
on part we must supply a boolean, true for the full information, 
false for the restricted information. See class for more details.

=====================================================================

Class : partList

We define a class partList, which describes all of the particles 
within the event. An instance of this class is initialised by 
supplying the larlite::storage_manager as an argument, eg.

partList P(storage);

This new list can now be used to access all of the anaParts within
the event. To loop over the particles in the event we can just use:

for (anaPart &part : P.List()){
	std::cout << part.ID(true) << std::endl;
}
