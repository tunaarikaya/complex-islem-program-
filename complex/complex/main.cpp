//
//  main.cpp
//  complex
//
//  Created by Mehmet Tuna Arıkaya on 17.05.2024.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef _complex_h
#define _complex_h
class complex
{
private:
 float reel;
 float imaginal;
 int power;
public:
 complex()
 {
 reel=0.0;
 imaginal=0.0;
 power=0;
 }
 complex(float r,float i,int p)
 {
 reel=r;
 imaginal=i;
 power=p;
 }
 ~complex(){}
 void setREEL(float r)
 {
 reel=r;
 }
 void setIMAGE(float i)
 {
 imaginal=i;
 }
 void setPOWER(int p)
 {
 power=p;
 }
 void setALL(float r,float i,int p)
 {
 reel=r;
 imaginal=i;
 power=p;
 }
 float getREEL()
 {
 return reel;
 }
 float getIMAGE()
 {
 return imaginal;
 }
 int getPOWER()
 {
 return power;
 }
 void print()
 {
 cout << reel;
 if (imaginal >= 0)
 cout << " + " << imaginal << "i";
 else
 cout << " - " << -imaginal << "i";
 cout << "^" << power << endl;
 }
 void setting()
 {
 power = 4;
 }
 void sum(complex a,complex b)
 {
 reel = a.reel + b.reel;
 imaginal = a.imaginal + b.imaginal;
 }
 void sub(complex a,complex b)
 {
 reel = a.reel - b.reel;
 imaginal = a.imaginal - b.imaginal;
 }
 void mult(complex a,complex b)
 {
 reel = a.reel * b.reel - a.imaginal * b.imaginal;
 imaginal = a.reel * b.imaginal + a.imaginal * b.reel;
 }
 void division(complex a,complex b)
 {
 float denominator = b.reel * b.reel + b.imaginal * b.imaginal;
 reel = (a.reel * b.reel + a.imaginal * b.imaginal) / denominator;
 imaginal = (a.imaginal * b.reel - a.reel * b.imaginal) / denominator;
 }
};
#endif
int main()
{
 float x,y;
 int z,select,repeat=1;
 complex a;
 complex b;
 while(repeat==1)
 {
 cout<<"Enter the real part of first complex number --> ";
 cin>>x;
 cout<<"Enter the imaginary part of first complex number --> ";
 cin>>y;
 cout<<"Enter the upper force of first complex number --> ";
 cin>>z;
 a.setALL(x,y,z);
 cout<<" -------> ";
 a.print();
 cout<<"\nEnter the real part of second complex number --> ";
 cin>>x;
 cout<<"Enter the imaginary part of second complex number --> ";
 cin>>y;
 cout<<"Enter the upper force of second complex number --> ";
 cin>>z;
 b.setALL(x,y,z);
 cout<<" -------> ";
 b.print();
 a.setting();
 b.setting();
 cout<<"\t.....AFTER SETTING.....\n\t.....First --> ";a.print();
 cout<<"\t.....Second--> ";b.print();
 cout<<"\n.....Please make your choice.....\n\t"
 <<"For summation press 1\n\t"
 <<"For subtraction press 2\n\t"
 <<"For multiplication press 3\n\t"
 <<"For division press 4\n\t"
 <<"--> ";
 cin>>select;
 switch(select)
 {
 case 1:
 a.sum(a,b);
 break;
 case 2:
 a.sub(a,b);
 break;
 case 3:
 a.mult(a,b);
 break;
 case 4:
 {
 if(b.getIMAGE()==0 && b.getREEL()==0)
 {
 cout<<"Division BY ZERO ERROR!!!"<<endl;
 break;
 }
 else
 {
 a.division(a,b);
 break;
 }
 }
 }
 cout<<"\nIf you would like to make a new operation\n"
 <<"press 1 or would not press 2\n-->";
 cin>>repeat;
 if(repeat==2)
 return 0;
 }
 return 0;
}
