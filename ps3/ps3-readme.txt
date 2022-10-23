/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Doulos Htet

Hours to complete assignment: 9

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment is about creating recursive triangles using recursive functions.
The executable file takes in the length of the side of triangle and the number
of recursion. Then, it draws the recursive triangles in a window.


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I created three members left, right and under vertices of the triangle where
the following recursive triangles are drawn. Then those three members are
used in base big triangle recursive function, and window resize function. 
The triangles created in the recursion are stored in a vector and the vector
acts as a base case. The recursion is performed for left, right and under 
vertices of each created triangles.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
baseTriangle->triangleLeft->move(basePosition.x-childLength/2, basePosition.y-childLength);

baseTriangle->triangleRight->move(basePosition.x + baseLength, basePosition.y);

baseTriangle->triangleUnder->move(basePosition.x, basePosition.y+baseLength);

If nothing is drawn, return, else get base triangle's  position and
get the positions for left, right and under triangles. I made under 
triangle as x origin and right triangle as y origin and calculated   
the positions for the triangles. 
 
 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned about implementing recursion to the next level. The Sierpinski 
triangle is a cool concept to learn and I also want to code Pythagorean
tree fractal.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Classmate

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I checked my cpp files with cpplint.py and found many errors but I didn't 
bother to change the style and formats so I leave them as they are but they 
pass the cpplint.py test
