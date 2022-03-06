/*this program swaps the values of two variables with the use of a temporary variable
using pointers*/
#include <iostream>
using namespace std;

int main()
{
int a;
int *pa=&a;
int b;
int *pb=&b;
int temp;
cout<<"Enter the first number:";
cin>>a;
cout<<"Enter the second number:";
cin>>b;
cout<<"Values of a and b:-\n";
cout<<"Before Swapping:\n";
cout<<a<<"  "<<b<<endl;
//swapping the values
temp=*pa;
*pa=*pb;
*pb=temp;
cout<<"After Swapping:\n";
cout<<a<<"  "<<b<<endl;
return 0;
}
