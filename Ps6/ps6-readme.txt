/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name:Doulos Htet

Hours to complete assignment:8
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment predicts the frequency of the next character in the string
with a given order k. The program then uses multimap to store kgram values
which are the order paired values with k lengths. The frequencies of kgram
are recorded and the frequencies of next value that followed kram are also
recorded to predict the probablity of next value happening. 



  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The multimap is used to store kgram, with k length from the input text file. 
Each element has its associated key and they are accessed through .first(key) and 
.second(element). The kgram values are stored using insert() function of multimap
with iterator position, and key, element. 


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
for(int i= 0; i<=inputText.length()-k -1; i++){
		for (auto &key : kgramMap){
			if (key.first == inputText.substr(i, k) && key.second.first == inputText.at(i + k)){
				key.second.second++;
				found = true;
			}
		}
		if(!found ){
			kgramMap.insert({inputText.substr(i,k), {inputText.at(i+k), 1}});
		}
		found = false;
	}

This is where kgram values are stored in RandWriter constructor. 


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes. I tested with boost for 5 cases, they all came out success with 
freq, freq with two parameters, orderK, kRand functions and RandWriter 
constructor.

/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, I impletemented exceptions and test every function except generate 
and they all pass the unit tests.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
RandWriter consturctor where textlength is 0 and k< o, throw invalid argument
two freq functions where kgram length is less or greater than k, throw runtime 
error exception
kRand function where kgram length is less or greater than k, throw runtime 
error exception


 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
N/A


/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/
N/A



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
classmate, the implementation of multimap 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
