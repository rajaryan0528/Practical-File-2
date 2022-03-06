/*This program implements run time polymorphism using pointer to the object
  ->Implments late binding */
#include <iostream>
using namespace std;
#include <cstring>

class Person
{
protected:
  int age;
  char name[255];
public:
    Person()
    {
      age=0;
      strcpy(name,"");
    }
     virtual void input()
    {
      cout<<"Enter name of the person:";
      cin.getline(name,255);
      cin.ignore();
      cout<<"Enter person's age:";
      cin>>age;
      return;
    }

    virtual ~Person()
    {
      cout<<"Deleting base class object."<<endl;
    };
    virtual void display()
    {
      cout<<"Person's name:"<<name<<endl;
      cout<<"Person's age:"<<age<<endl;
      return;
    }
};

class Student: public Person
{
  int roll;
  float marks;
  char course[50];
public:
    Student()
    {
      roll=0;
      marks=0.0;
      strcpy(course," ");
    }
    void input()
    {
      Person::input();
      //cout<<"Enter course enrolled in :";
      //cin.getline(course,50);
      cout<<"Enter roll no :";
      cin>>roll;
      cout<<"Enter total marks : ";
      cin>>marks;
      cin.ignore();
      /*As cin>> leaves behind a '\n' when we press enter and because of that when we use getline()
      it picks up the \n and takes no input as it finds \n in the input stream */
      return;
    }
    ~Student()
    {
      cout<<"Object of the Student class is deleted."<<endl;
    }
    void display()
    {
      Person::display();
      cout<<"Student's roll number:"<<roll<<endl;
      //cout<<"Course Enrolled In :"<<course<<endl;
      cout<<"Student's Marks:"<<marks<<endl;
      return;
    }

};

class Teacher: public Person
{
  int salary;
  char  dept[50];
public:
    Teacher()
    {
      salary=0;
      strcpy(dept,"");
    }
    void input()
    {
      Person::input();
      cout<<"Enter salary :";
      cin>>salary;
      cin.ignore();
      cout<<"Enter dept. :";
      cin.getline(dept,50);
    }
    void display()
    {
      Person::display();
      cout<<"Teacher's Salary :"<<salary<<endl;
      cout<<"Department :"<<dept<<endl;
      return;
    }
    ~Teacher()
    {
      cout<<"Object of the teacher class is deleted."<<endl;
    }
};
int main()
{
  //if display is not declared virtual in the base class the pointer will call display function of the base class only both times
  Student s;
  Teacher t;
  Person *p1= &s;
  p1->input();
  p1->display();
  Person *p2= &t;
  p2->input();
  p2->display();
  return 0 ;

}
