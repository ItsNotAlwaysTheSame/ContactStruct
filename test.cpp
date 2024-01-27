#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <regex>
#include"validation.h"
#include"testsearch1.h"
#include "delete.h"
#include <cctype>

using namespace std;



int main()
{
    int cases=-1;
    bool loop=true;
    
    do
    {
        cout<<"\n\n\t (0) quit\n\t (1) delete\n\t (2) add\n\t (3) search"<<endl;
        cout<<"\twhich case: "<<endl;
        cout<<"\t";
        cin>>cases;
         switch (cases)
    {
        case 0: 
        loop=false;
        break;
    case 1:
        Delete();
        break;
        
    case 2: 
        add();
        break;
    case 3:
        testsearch1("data.txt");
        break;
    default:
        cout<<"\twrong data,\n follow structure in menue\n";
        break;
        
    }
    } while (loop==true);
    
   
  
    return 0;
    
}