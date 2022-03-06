
/*matrix operations using OOP*/
#include <iostream>
using namespace std;
#define  MAX_DIM 100


class Matrix
{
 private:
    int row=0,column=0;
    int arr[MAX_DIM][MAX_DIM];
 public:
   Matrix(int r,int c);
   void input();
   void show();
   friend void add(Matrix &a, Matrix &b);
   friend void multiply(Matrix &a, Matrix &b);
   friend void subtract(Matrix &a, Matrix &b);
   void transpose();
};

Matrix::Matrix(int r,int c)
{
   row=r;
   column=c;
   for(int i=0;i<row;i++)
   {
     for(int j=0;j<column;j++)
       arr[i][j]=0;
   }
}
void Matrix::input()
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
      cout<<"Enter element at "<<i<<","<<j<<" index:";
      cin>>arr[i][j];
    }
  }
  cout<<"\n";
}
 void Matrix::show()
 {
   for(int i=0;i<row;i++)
       {
         for(int j=0;j<column;j++)
         {

            cout<<"\t"<<arr[i][j]<<"\t";
         }
         cout<<"\n";
        }
    cout<<endl;
  }

void add(Matrix &a, Matrix &b)
   {
     if(a.row!=b.row || a.column!=b.column)
        cout<<"Matrix addition not possible."<<endl;
     else
     {
       Matrix sum(a.row, a.column);
       for(int i=0;i<sum.row;i++)
       {
         for(int j=0;j<sum.column;j++)
         {
            sum.arr[i][j]=a.arr[i][j]+b.arr[i][j];
         }
       }
      cout<<"Result of the addition of the two matrices:-"<<endl;
      sum.show();
     }
   }

void subtract(Matrix &a, Matrix &b)
   {
     if(a.row!=b.row || a.column!=b.column)
        cout<<"Matrix subtraction not possible."<<endl;
     else
     {
       Matrix diff(a.row, a.column);
       for(int i=0;i<diff.row;i++)
       {
         for(int j=0;j<diff.column;j++)
         {
            diff.arr[i][j]=a.arr[i][j]-b.arr[i][j];
         }
       }
      cout<<"Result of the subtraction of the two matrices:-"<<endl;
      diff.show();
     }
   }
void  multiply(Matrix &a, Matrix &b)
   {
     // number of columns of first matrix should be equal to the number of the rows of the second matrix
     if(a.column!=b.row)
        cout<<"Matrix  multiplication not possible."<<endl;
     else
     {
       //r1*p p*c2 -> r1*c2
       Matrix product(a.row,b.column);
       for(int i=0;i<a.row;i++)
       {
         for(int j=0;j<b.column;j++)
         {
           int t=0;
           for(int k=0;k<a.column;k++)
                 t+=a.arr[i][k]*b.arr[k][j];
           product.arr[i][j]=t;
         }
       }
      cout<<"Result of the multiplication of the two matrices:-"<<endl;
      product.show();
     }
   }

void Matrix::transpose()
   {
       Matrix transPose(this->column,this->row);
       for(int i=0;i<column;i++)
       {
         for(int j=0;j<row;j++)
         {
            transPose.arr[i][j]=this->arr[j][i];
         }
       }
      cout<<"Result of performing transpose on the matrix:-"<<endl;
      transPose.show();
     }

int main()
{
  int r1,c1,r2,c2;
  cout<<"Enter no. of rows in first matrix:";
  cin>>r1;
  cout<<"Enter no. of columns in first matrix:";
  cin>>c1;
  cout<<"Enter no. of rows in second matrix:";
  cin>>r2;
  cout<<"Enter no. of columns in second matrix:";
  cin>>c2;
  Matrix A(r1,c1);
  Matrix B(r2,c2);
  cout<<"Enter elements for matrix 1:"<<endl;
  A.input();
  cout<<"Enter elements for matrix 2:"<<endl;
  B.input();
  cout<<"Matrix 1:"<<endl;
  A.show();
  cout<<"Matrix 2:"<<endl;
  B.show();
  int ch;
  do
  {
    cout<<"Operations you can perform on these matrices."<<endl;
    cout<<"1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.TRANSPOSE\n5.EXIT\n";
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
       case 1:
         add(A,B);
         break;
       case 2:
          subtract(A,B);
          break;
       case 3:
           multiply(A,B);
           break;
       case 4:
           char chMat;
           cout<<"Select the Matrix (A/B).\nEnter your choice:"<<endl;
           cin>>chMat;
           if(chMat =='A')
             A.transpose();
           else
             B.transpose();
          break;
       default:
           if(ch==5)
             cout<<"Task Completed."<<endl;
           else
             cout<<"Please enter a valid choice."<<endl;
           break;
    }
  }while(ch!=5);

  return 0;
}
