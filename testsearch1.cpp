#include <iostream>
#include <fstream> //For file operation
#include <regex>  // For regular expression
//#include"testsearch.h"
#include"testsearch1.h"
using namespace std;
string testsearch(const smatch& m) {
	string lineMatch;
	lineMatch += m.prefix();
	lineMatch += m.str(); 
	lineMatch += m.suffix();

	return move(lineMatch);
}

void testsearch1(string filename)
{
    
    std::ifstream fp(filename);
	if(!fp.is_open()) {
		std::cout << "Error in openning the file \n";
		exit(EXIT_FAILURE);
	}
	

		std::string word;
	std::cout << "Enter the word to be searcher: ";
	//Word to be matched
	std::cin >> word;
	int lineCount = 0;

	std::string line;
	std::regex reg(word,std::regex_constants::grep);//regex object which use grep syntax
	std::smatch match;

	while(getline(fp,line)) {
		
		//fprintf(stdout,"%s",regex_search(line,match,reg) ? testsearch(match/*,lineCount*/).c_str() :"\n");
		regex_search(line,match,reg);
		if(regex_search(line,match,reg)==1)
		{
			cout<<"\n\t\t\t\t" <<testsearch(match)/*.c_str()*/<<endl;
		}
		//cout<<testsearch(match)/*.c_str()*/<<endl;
		++lineCount;
	}
	
	
	
	//fp.close();

}



