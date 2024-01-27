#include <iostream>
#include <regex>
#include <fstream>
#include "validation.h"
using namespace std;

std::string firstnameadd(std::string firname)
{
    regex finame;
    finame=("[A-Z][a-z]+");
    do
        {
            cout<<"\n\tenter name (start with capital letter): ";
            cin>>firname;
        } while (!regex_match(firname, finame));
    return firname;
}
std::string lastnameadd(std::string lastname)
{
    regex laname;
    laname=("[A-Z][a-z]+");
    do
        {
             cout<<"\n\tenter last name (start with capital letter): ";
            cin>>lastname;
        } while (!regex_match(lastname, laname));
    return lastname;
}
std::string numberadd(std::string number)
{
    regex numm;
    numm=("[0][0-9]{9}");
     do
        {
             cout<<"\n\tenter number: ";
            cin>>number;
        } while (!regex_match(number, numm));
    return number;
}
std::string eposadd(std::string epost)
{
    regex epo;
    epo="[_A-Za-z0-9-]+(.[_A-Za-z0-9-]+)*@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,4})";
     do
        {
             cout<<"\n\tenter epost: ";
            cin>>epost;
        } while (!regex_match(epost, epo));
    return epost; 
}
std::string addressadd(std::string address)
{
    regex adress;
    adress=("[A-Z][a-z]+[-][A-Z][a-z]+[-][0-9]{2}[-][A-Z]");
     do
        {
             cout<<"\n\tenter address: ";
            cin>>address;
        } while (!regex_match(address, adress));
    return address;
}
std::string birthadd(std::string birth)
{
    regex birthd;
    birthd=("[0-9-]{4}[/][0-9-]{2}[/][0-9-]{2}");
     do
        {
             cout<<"\n\tenter birthday: ";
            cin>>birth;
        } while (!regex_match(birth, birthd));
    return birth;
}
std::string moreadd(std::string more)
{
    regex m;
    m=("[(][_A-Za-z0-9-]+(.[_A-Za-z0-9-]+)*[)]");
     do
        {
             cout<<"\n\tenter information: ";
            cin>>more;
        } while (!regex_match(more, m));
    return more;
}
vector<string> make_vector1(string lastname, string nummer, string epos, string addres, string birthd, string more) {
  std::vector<string> result;
  result.push_back(lastname);
  result.push_back(nummer);
  result.push_back(epos);
  result.push_back(addres);
  result.push_back(birthd);
  result.push_back(more);
  return result;
}
void add()
{
    string fname, lname, number, epost,address, birthd, more, nametoerase, temp, item ;
    int cases=2;
    
    map<string, vector<string>,less<>>  namefirst;
    ifstream input;
    input.open("data.txt");
    if(!input.is_open()) {
		cout << "Error in openning the file \n";
		exit(EXIT_FAILURE);
	}
	else
	{
input>>fname>>lname>>number>>epost>>address>>birthd>>more;
    //temp=fname+" "+ lname+" "+  number+" "+  epost+" "+ address+" "+  birthd+" "+ more;

    while (!input.eof())
    {
    namefirst.insert(make_pair(fname, make_vector1(lname, number, epost, address, birthd, more))); 
    input>>fname>>lname>>number>>epost>>address>>birthd>>more;
    //namefirst.insert(make_pair(fname, make_vector1(lname, number, epost, address, birthd, more)));
    //file.make_vector1(fname, lname, number, epost, address, birthd, more);
    
    }
     input.close();

 
     if(cases==2)
     {
        fname=firstnameadd(fname);
        lname=lastnameadd(lname);
        number=numberadd(number);
        epost=eposadd(epost);
        address=addressadd(address);
        birthd=birthadd(birthd);
        more=moreadd(more);
       namefirst.insert(make_pair(fname, make_vector1(lname, number, epost, address, birthd, more)));
        /*temp=fname+" "+ lname+" "+  number+" "+  epost+" "+ address+" "+  birthd+" "+ more;
        sort(file.begin(), file.end());
        file.push_back(temp);*/
       //write new order list back out
     }
    
    ofstream out("data.txt", ios::out | ios::trunc);

for (auto& element : namefirst)
    {
        out <<"\n" <<element.first;
        for (auto& str : element.second)
        {
            out <<" " <<str ;
        }
    }
    /*
for(map<string, vector<string>,less<>> ::const_iterator i = namefirst.begin(); i != namefirst.end(); ++i)
{
	out << *i << endl;
}*/
out.close();
    }
}