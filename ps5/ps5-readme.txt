/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Doulos Htet	

Hours to complete assignment: 8

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
I use dynamic programming in optDistance() function - first filling out
the bottom-most and right-most with 2 multiples. Then, I use the nested 
for-loops to fill out the 2 dimensional array. I have already implemented 
the min(int, int, int) function which takes in 3 arguments to compare the 
lowest value. By using that function, I am able to fill out the array by 
comparing down + 2, right + 2, and cross + penaly value (0 or 1).



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: ./EDistance < ../sequence/endgaps7.txt

Expected output: Edit Distance: 4
		 Execution time is 3.7e-05 seconds 

What happened: The code worked fine but runtime is quick with 0.000037.


/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/

CPU speed in MHz - 3790 MHz
Implementation method: Needleman-Wunsch
Matrix method: 2 dimensional array
Operating system: ubuntu linux
Cpu-type- Amd ryzen 5 3600x 6 core Processor
RAM: 32GB - this means that the larger the RAM, the faster the execution time.


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 0.00000416              
b = 1.99
largest N = 46827

ecoli2500.txt				ecoli5000.txt
a * 2500^b = 24.02			a * 5000^b = 95.66

largest N,    a * N^b = 8192
	      0.00000416 * N^1.99 = 8192 
	

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
I tested valgrind with each data file from below and recorded the distance,
time, and memory. I attached each massif.out files in my submission in order. 
Yes, the memory usage nearly match. 


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt	      118	     0.071275            24.02
ecoli5000.txt	      160            0.285771            95.66 
ecoli7000.txt         194            0.553955           187.30
ecoli10000.txt        223            1.130900           382.00
ecoli20000.txt       3135            4.870370          1491.00
ecoli28284.txt       8394           10.140500          2981.00

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 1.13*10^-8
b = 2
largest N = 2765143

ecoli7000.txt				ecoli10000.txt
a * 7000^b = 0.553955			a * 10000^b = 1.130900 

largest N,    a * N^b = 86400
	      1.13*10^-8 * N^2 = 86400 

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
N/A



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
I ask from my classmate how to compute a * N^b = t and a * N^b = s. I was
confused on what values to plug in for a and b.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A