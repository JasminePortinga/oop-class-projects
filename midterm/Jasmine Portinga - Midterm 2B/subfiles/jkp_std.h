// since this file is just to facilitate my own laziness, i'm going to code it like it's not getting graded
#ifndef jkp_std
#define jkp_std
#include <iostream>
#include <iomanip>
#include <string>
class project {
	public:
		project(){}; //default constructor

		void title(std::string project_name) { //if i were doing this for others to use i'd also add in a var for user name, but this is really just bc i'm lazy and don't want to have to format my titles all the time. 
		std::string stars{"****************************************************************"}; //64 max should be enough, right?
		std::string title_line{"* " + project_name + " - Jasmine Portinga *"};
		unsigned int title_length{title_line.length()};
		std::cout << std::setw(50 + ceil(title_length/2)) << stars.substr(0, title_length) << std::endl;
		std::cout << std::setw(50 + ceil(title_length/2)) << title_line << std::endl;
		std::cout << std::setw(50 + ceil(title_length/2)) << stars.substr(0, title_length) << std::endl << std::endl;
		}
	private:
};
#endif //end jkp_std