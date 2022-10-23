/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Doulos Htet

Hours to complete assignment : 10

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the assignment, all the 37 key notes have different frequency
and can be played when pressing corresponding buttons. The loop where the 
frequencies are created 440 × 2^(i - 24) / 12 and sound and soundbuffer 
vectors are the working parts of the assignmet.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
No, I only attempted the guitar part of the main assignment.

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, the exceptions are thrown when frequencies and vector sizes are 
added as negative numbers which they should not be and those exceptions 
are implemented in StringSound(double frequency) and StringSound(std::
vector<sf::Int16> init) constructors. 


/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
I did not implement any lambda expressions.


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, all the .cpp and .h files pass cpplint. I check it by running commands
cpplint.py KSGuitarSim.cpp
cpplint.py StringSound.h
cpplint.py StringSound.cpp
cpplint.py CircularBuffer.h
cpplint.py CircularBuffer.cpp in the directory.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I received a few helps from my classmate. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had to ask for help from my classmate about the implementation of 
pluck and tic functions which are a bit complicated. KSGuitarSim.cpp was 
easy to implement since SSLite.cpp acts as a refrence for almost the whole 
code.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
