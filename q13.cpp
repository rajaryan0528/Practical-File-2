/* menu driven program to perform operations on string
  -->Address of each character of string
  -->Concatenate using strcat function
  -->Concatenate without using strcat function
  -->Compare two strings
  -->Calculate number of vowels
  -->Length of string using pointers
  -->All lowercase to uppercase characters
  -->All uppercase to lowercase characters
  -->Reverse the string
*/
#include <iostream>
#include <cstring>
#include <cctype>         //character manipulation functions library
using namespace std;

int len(char *str);
void toUpper(char s[])
{
  char t[255];
  strcpy(t,s);
  for(int i=0;i<len(s);i++)
  {
    t[i]=toupper(t[i]);
  }
  cout<<"String in uppercase:"<<t<<endl;
};
void toLower(char s[])
{
  char t[255];
  strcpy(t,s);
  for(int i=0;i<len(s);i++)
  {
    t[i]=tolower(t[i]);
  }
  cout<<"String in lowercase:"<<t<<endl;
};
void reverse(char s[])
{
   char t[len(s)+1];
   for(int i=0;i<len(s);i++)
   {
      t[i]=s[len(s)-1-i];
   }
   cout<<t<<endl;
};
void concat(char a[],char b[])
{
  char t[len(a)+len(b)+1];
  for(int i=0;i<len(a);i++)
  {
    t[i]=a[i];
    t[i+len(a)]=b[i];
  }
  cout<<"Concatenated string is :"<<t<<endl;
};

void concatWithStrCat(char a[],char b[])
{
    char t[len(a)+len(b)+1];
    strcpy(t,a);
    strcat(t,b);
    cout<<"Concatenated string using strcat() is :"<<t<<endl;
};

int countVowels(char *s)
{
  int count=0;
   for(char *c=s;*c!='\0';c++)
   {
     if(tolower(*c)=='a' ||tolower(*c)=='e' ||tolower(*c)=='i' || tolower(*c)=='o' || tolower(*c)=='u')
       count++;
   }
   return count;
};

void compare(char s1[], char s2[])
{
  if(len(s1)==len(s2))
  {
    bool flag=true;
    for(int i=0;i<len(s1);i++)
    {
     if(s1[i]!=s2[i])
       flag=false;
       cout<<"Lengths of both the strings are equal but they are not same."<<endl;
       break;
    }
   if(flag)
    cout<<"Both the strings are same."<<endl;
  }
  else if(len(s1)>len(s2))
    cout<<"Length of  the first string is greater than the second string."<<endl;
  else
    cout<<"Length of the second string is greater  than the first string."<<endl;

};

int  len(char *str)
{
  //calculates length of the string using pointers
  int length=0;
  for(char *c=str;*c!='\0';c++)
  {
    length++;
  }
  return length;
};

void showAddress(char *a)
{
  for(int i=0;i<len(a);i++)
  {
    cout<<(*a+i)<<"  ";
  }
  cout<<endl;
};

int main()
{
  int ch=0;
  char string1[255], string2[255];
  cout<<"Enter the string:";
  cin.getline(string1,255);
  cout<<"Enter another string:";
  cin.getline(string2,255);
  do
  {
    cout<<"Operations you can perform on a string.\n";
    cout<<"1.Display address of each character in the string."<<endl;
    cout<<"2.Concatenate two strings without using strcat()."<<endl;
    cout<<"3.Concatenate two strings using strcat()."<<endl;
    cout<<"4.Compare two strings."<<endl;
    cout<<"5.Calculate the length of the string using pointers."<<endl;
    cout<<"6.Convert the string into lowercase."<<endl;
    cout<<"7.Convert the string into uppercase."<<endl;
    cout<<"8.Reverse the string."<<endl;
    cout<<"9.Count the number of vowels."<<endl;
    cout<<"10.Exit"<<endl;
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:
              cout<<"Address of elements in the first string."<<endl;
              showAddress(string1);
              cout<<"Address of the elements in the second string."<<endl;
              showAddress(string2);
           break;
      case 2:
           concat(string1, string2);
           break;
      case 3:
           concatWithStrCat(string1,string2);
           break;
      case 4:
           compare(string1, string2);
           break;
      case 5:
            cout<<"Length of the first string: "<<len(string1)<<endl;;
            cout<<"Length of the second string: "<<len(string2)<<endl;
            break;
      case 6:
            toLower(string1);
            toLower(string2);
            break;
      case 7:
            toUpper(string1);
            toUpper(string2);
            break;
      case 8:
            cout<<"String 1 reversed :";
            reverse(string1);
            cout<<"String 2 reversed :";
            reverse(string2);
            break;
      case 9:
           cout<<"Vowels count in string 1 :"<<countVowels(string1)<<endl;
           cout<<"Vowels count in string 2 :"<<countVowels(string2)<<endl;
           break;
      default:
           if(ch==10)
             cout<<"Exiting Task."<<endl;
           else
              cout<<"Please enter a valid choice."<<endl;
    }
  }while(ch !=10);
  return 0;
}
