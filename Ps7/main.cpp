#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int argc, const char* argv[]){
	if(argc != 2){
		std::cout << "./ps7 device1_intouch.log\n";
		return 0;
	}
	
	int lines_scan = 1;
	int boot_success = 0; 
	int boot_total = 0;
	
	std::string file_name(argv[1]);
	std::string output_name = file_name + ".rpt";
	std::string report = "";
	std::string boots = "";
	
	std::string begin_date = "";
	std::string end_date = "";
	
	std::string full_date;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	
	ptime begin; 
	ptime end;
	
	date date1;
	date date2;
	
	time_duration time_diff;
	
	std::string start_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
	start_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";
	start_string += "sever started";
	std::string end_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
	end_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
	end_string += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";
	
	boost::regex start_regex(start_string, boost::regex::perl);
	boost::regex end_regex(end_string);
	
	boost::smatch sm;
	
	std::string line;
	std::ifstream file(file_name.c_str());
	
	bool found_start = false;
	
	if(file.is_open()){
		while (getline(file, line)){
			begin_date.clear();
			end_date.clear();
			
			if(boost::regex_search(line, sm, start_regex)){
				begin_date = sm[1] + "-" + sm[2] + "-" + sm[3];
				begin_date += " " +sm[4] + ":" + sm[5] + ":" +sm[6];
				
				full_date = sm[1] + "-" + sm[2] + "-" + sm[3];
				date1 = date(from_simple_string(full_date));
				
				hours = std::stoi(sm[4]);
				minutes = std::stoi(sm[5]);
				seconds = std::stoi(sm[6]);
				
				begin = ptime(date1, time_duration(hours, minutes, seconds));
				
				if(found_start == true){
					boots += "**** Incomplete boot **** \n\n";
				}
				
				boots += "=== Device boot ===\n";
				boots += std::to_string(lines_scan) + "(" + file_name + "): ";
				boots += begin_date + "Boot Start\n";
				
				boot_total++;
				found_start = true;
			}
			if (boost::regex_match(line, sm, end_regex)){
				end_date = sm[1] + "-" + sm[2] + "-" + sm[3];
				end_date += " " +sm[4] + ":" + sm[5] + ":" +sm[6];
				
				full_date = sm[1] + "-" + sm[2] + "-" + sm[3];
				date2 = date(from_simple_string(full_date));
				
				hours = std::stoi(sm[4]);
				minutes = std::stoi(sm[5]);
				seconds = std::stoi(sm[6]);
				
				end = ptime(date2, time_duration(hours, minutes, seconds));
				
				boots += std::to_string(lines_scan) + "(" + file_name + "): ";
				boots += end_date + "Boot Completed\n";
				
				time_diff = end - begin;
				
				boots += "\tBoot Time: ";
				boots += std::to_string(time_diff.total_milliseconds()) + "ms \n\n";
				
				boot_success++;
				
				found_start = false;
			}
			lines_scan++;
		}
		file.close();
	}
	report += "Device Boot Report";
	report += "\n\nIntouch log file: " + file_name + "\n";
	report += "Lines scanned: " + std::to_string(lines_scan) + "\n\n";
	report += "Device boot count: initiated = " + std::to_string(boot_total);
	report += ", completed: " + std::to_string(boot_success) + "\n\n\n";
	
	boots.erase(boots.end()-1);
	report += boots;
	std::ofstream out(output_name.c_str());
	out << report;
	out.close();
	
	return 0;	
}
