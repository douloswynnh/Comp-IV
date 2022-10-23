/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Doulos Htet
Hours to complete assignment: 8 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment is to display planets and sun in a window. The planets' 
information was given in nbody.zip file and I had to create Celestial.h,
Celestial.cpp, Universe.h, Universe.cpp, and main file which all contain
reading inputs code and displaying read files in a loop within vector.


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The main part of the assignment is to read the radius and the number of 
planets from input files. Then, they are stored in a vector and each is 
pushed back using push_back data structure. Then, they are drawn in a window
with thier specified information such as position. 

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The vector that creats the planets input is made shared_ptr and that shared 
vector is used again to hold the created planets.

vector of shared pointer: std::vector<std::shared_ptr<CelestialBody> > SolarSystem;
shared pointer reused : std::shared_ptr<CelestialBody> planet(new CelestialBody(radius));

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I received help from my classemate. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
One problem I had was with the position calculation of the planets. All the planets
were stuck at the top left corner as I didn't use the window's height and width (or 
x and y) as one of my parameters in the calculation. 

The other problem was getting the image background appear in the window. The image
was too big of a size and only part of it was appearing in the window. Eventually
I had to use texture.getSize().x and y so that the image scales with the window.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/