/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Doulos Htet
Hours to complete assignment:5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment is to implement the CircularBuffer class which includes
creating empty ring, returning size, checking if it's empty or full, 
inserting, removing and peeking items. 



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Each function has its own implementation but the test.cpp tests all the 
function to see if they are working. Enqueue, peek, and constructors all 
throw exceptions - runtime errors and invalid argument. 
	

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Test.cpp implements all the boost tests of the functions.
CircularBuffer c(3);
	c.enqueue(1);
	c.enqueue(2);
	c.enqueue(3);
	BOOST_REQUIRE_THROW(c.enqueue(4), std::runtime_error);
	BOOST_REQUIRE(c.dequeue()== 1);
	BOOST_REQUIRE_NO_THROW(c.peek()==2);
	BOOST_REQUIRE(c.dequeue()==2);
	BOOST_REQUIRE(c.dequeue()==3);
	BOOST_REQUIRE_THROW(c.peek(), std::runtime_error);




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes.



/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

Yes. I make sure all the exceptions and implementations should work as 
they are intended- throwing exceptions when necessary and not throwing 
exceptions when they're not required.



/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
The program implements stack data structure which is removing and insertion
happen at one end. The time complexity for enqueue, dequeue, and peek is 
O(1).



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A