#include <iostream>
using namespace std;

class Box
{
private:
  float vol,surfArea;
public:
    int lngth,brdth,height;
    Box()
    {
      lngth=0;
      brdth=0;
      height=0;
    }

    void isCube();
    void input();
    void volume();
    void show()
    {
      cout<<"Lenght:"<<lngth<<endl;
      cout<<"Breadth:"<<brdth<<endl;
      cout<<"Height:"<<height<<endl;
    }
    void surfaceArea();
    void operator +(Box &ob1);
    friend void operator==(Box &ob1,Box &ob2);
    void operator =(Box &ob1);
};

void Box::isCube()
{
  if(lngth==brdth && height==lngth && brdth==height)
     cout<<"Box is a cube."<<endl;
  else
     cout<<"Box may be a cuboid."<<endl;
}
void operator==(Box &ob1,Box &ob2)
{
  if(ob1.lngth==ob2.lngth && ob1.brdth==ob2.brdth && ob1.height==ob2.height)
     cout<<"Boxes are equal."<<endl;
  else
     cout<<"Boxes are unequal."<<endl;
}
void Box ::operator =(Box &ob1)
{
  lngth=ob1.lngth;
  brdth=ob1.brdth;
  height=ob1.height;
}
void Box ::operator +(Box &ob1)
{
   this->lngth+=ob1.lngth;
   this->brdth+=ob1.brdth;
   this->height+=ob1.height;
}
void Box::input()
{
  cout<<"Enter length of the box:";
  cin>>lngth;
  cout<<"Enter breadth of the box:";
  cin>>brdth;
  cout<<"Enter height of the box:";
  cin>>height;
}

void Box::volume()
{
  vol=lngth*brdth*height;
  cout<<"Volume of the box :"<<vol<<endl;
}

void Box::surfaceArea()
{
  surfArea=2*(lngth*brdth+brdth*height+height*lngth);
  cout<<"Surface Area of the box :"<<surfArea<<endl;
}

int main()
{
  Box b1,b2,b3;
  cout<<"Dimensiosn of box 1."<<endl;
  b1.input();
  cout<<"Dimensiosn of box 2."<<endl;
  b2.input();
  b1.volume();
  b2.volume();
  b1==b2;
  cout<<"Result of the addition of two box objects."<<endl;
  b1+b2;
  b1.show();
  b3=b2;
  cout<<"Box 3 after it was assigned box 2 by operator overloading."<<endl;
  b3.show();
  cout<<"Checking whether box 3 is a cube or not.";
  b3.isCube();
  return 0 ;

}
