//addition of lenghts and  their subtraction

#include <iostream>
using namespace std;

class Length
{
private:
  float feet,inches,inInches,inFeet;
public:
    Length()
    {
      feet=0;
      inches=0;
    }

    void input();
    friend void display(Length &a);
    void operator +(Length &ob1);
    void operator -(Length &ob1);
    void operator ==(Length &ob2);
};
void Length ::operator +(Length &ob1)
{
   this->inches+=ob1.inches;
   while(this->inches>12)
   {
     this->inches=this->inches-12;
     this->feet++;
   }
   this->feet+=ob1.feet;
}

void Length ::operator -(Length &ob1)
{
  if((this->inches)<ob1.inches)
  {
   bool run =true;
   while(run !=false)
   {
     this->inches+=12;
     this->feet--;
     if(this->inches >=ob1.inches)
         run=false;
   }
 }
   this->inches-=ob1.inches;
   this->feet-=ob1.feet;
}

void Length ::operator ==(Length &ob1)
{
   this->inches=ob1.inches;
   this->feet=ob1.feet;
}

void display(Length &a)
{
  cout<<"Feet :"<<a.feet<<"'"<<endl;
  cout<<"Inches :"<<a.inches<<endl;
}
void Length::input()
{
  cout<<"Enter dimensions in feet:";
  cin>>feet;
  cout<<"Enter dimensions in inches:";
  cin>>inches;
}

int main()
{
  Length l1,l2,l1Copy;
  cout<<"Magnitude of Data Set 1 should be greater than Data Set 2 otherwise subtraction of the two lenghts may give negative result."<<endl;
  cout<<"-----Data Set 1-----"<<endl;
  l1.input();
  l1Copy=l1;
  cout<<"-----Data Set 2-----"<<endl;
  l2.input();
  cout<<"--------------------------------------------------------------"<<endl;
  cout<<"----Result of the addition of the two lengths----"<<endl;
  l1+l2;
  display(l1);
  l1Copy-l2;
  cout<<"----Result of the subtraction of the two lengths----"<<endl;
  display(l1Copy);
  return 0 ;

}
