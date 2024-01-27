#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
#include"validation.h"
#include"delete.h"
using std::string;
using namespace std;
void Delete()
{
vector<string> file;
string temp;

ifstream infile("data.txt");
 if(!infile.is_open()) {
		cout << "Error in openning the file \n";
		exit(EXIT_FAILURE);
	}
	else
	{
while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
// done reading file
infile.close();

string item;
//cout<<"enter item: ";
  //      cin>>item;
string c=firstnameadd(item);
bool erase=true;
char b;
int i = 0;
	while ( i < (int)file.size()&& erase)
	{
		++i;
		if(file[i].substr(0, c.length()) == c)
	{
		
			cout<<file[i]<<endl;
			cout<<"do u wanna erase this name: "<<endl;
			cin>>b;
			if (b=='y')
			{
				file.erase(file.begin() + i);
				cout << "name erased!"<< endl;
				erase=false;
			}
			else if(b=='n')
			{
				erase=true;
			}
			
			
	
	}
	
	}





	
	
	




ofstream out("data.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}
out.close();
	}
}