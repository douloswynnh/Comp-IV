/**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name:Doulos 


Hours to complete assignment: 6


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I tested with device_intouch files and produce .rpt files.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
std::string start_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";

	start_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";

	start_string += "sever started";

	std::string end_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";

	end_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";

	end_string += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";

	

	boost::regex start_regex(start_string, boost::regex::perl);

	boost::regex end_regex(end_string);
start string was 4 digits with range 0 to 9(year), 2 digits for month and year.
server started is concatenated from behind. 
end string is the same as start start string and concatenated with success
determiner "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080"

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
The code reads in the log one at a time and then outputs the report log 
file with .rpt added behind. The hours, minutes, seconds are initialized 
to 0 first. The regex from above was created and added to boost regex as 
start regex and end regex. While loop to find the matched regex string, 
and if we already find the start, it counts as incomplete boot and if we 
can find a successful boot, the end date and full date will find the match
string again with boot completed report at the end.The success boot times 
are counted and incremented evertime with completed boot. Lines scan is 
also incremented evertime with each line scanned. Then, the report is added
at the end with the name of the .rpt file, lines scanned, boot count, and 
completed count, and boot time. 


/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
N/A




/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
classmate


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
cpplint main file erros 162 but passed.