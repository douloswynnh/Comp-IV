/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name:
Hours to complete assignment:
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
The assignment is about XOR operator and shifting bits to the left by one. 
The constructor just take in string seed of 16 digits and step() function 
takes in bits at 15, 13, 12, and 10 and XOR it and get the result. The generate
function takes in int parameter and translates the seed from binary to decimal.
For shifting digits, and translating binary to decimal, I used loops to get through
each numbers.

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
Binary to decimal conversion forumla of multiplying from leftmost digit with
 2^n*(0 or 1). 

/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
The additional test 1 is for testing the shifting of the seed from left to right
with step() and the other test is by using generate(k) and see if the decimal 
number is equal to the number generated. 

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
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