/*frequency table for characters present in the given input */
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
  string text;
  cout<<"Enter the text:";
  getline(cin,text);
  cout<<endl;
  int frequency[26]={0};
  char letters[26];
  char t='a';
  for(int i=0;i<26;i++)
  {
    letters[i]=t;
    t++;
  }

for(int i=0;i<26;i++)
{
  if(text[i] !=' ')
  {
    for(int j=0;j<26;j++)
    {
      if(letters[j] ==tolower(text[i]))
      {
        frequency[j]++;
      }
    }
  }
}

cout<<"Frequency table for the elements presents in the entered text.\nUppercase and Lowercase letters have been treated alike.\n"
    <<"Space is not counted."<<endl;
cout<<endl;
cout<<"\t Letter"<<"\t  Frequency"<<endl;
for(int i=0;i<26;i++)
{
  cout<<"\t|"<<letters[i]<<"\t | \t"<<frequency[i]<<" |"<<endl;
}
return 0;
}
