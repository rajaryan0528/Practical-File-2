/*this program copies characters from one file to another
after removing whitespaces */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  char ch;
  ofstream outStrm;
  ifstream inStrm;
  inStrm.open("demo.txt");
  outStrm.open("demo_copy.txt");
  while(inStrm.get(ch))
  {
    if(ch !=' ')     //checking for whitespaces
     outStrm.put(ch); //writing in the destination file
  }
inStrm.close();
outStrm.close();
return 0;
}
