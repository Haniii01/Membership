//
//  class.h
//  c++_exercise
//
//  Created by cappuccino  on 2021/7/16.
//

#ifndef class_h
#define class_h
#include<iostream>
#include<string>
using namespace std;
//”√ªß¿‡∫Ø ˝…˘√˜
class Users
{
protected:
    int passwd;
    string bir;
    string name;
    string sex;
    double cum;//¿€ª˝œ˚∑—
    string grade;//ª·‘±µ»º∂
    double balance;
public:
    Users(string na, string se, string bi, int pa);
    Users(string na, string se, string bi, int pa,double c,string gr,double b);
    string getname();
    string getsex();
    string getbirth();
    int getpasswd();
    double getcum();
    string getgrade();
    double getbalance();
    void setbalance(double m);
    void setgrade(string m);
    //new
    Users(){};
    virtual void operMenu()=0;
};
class administrator {
protected:
    string name;
    int passwd;
public:
    administrator(string n, int pa);
    string getad_name();
    int getad_passwd();
};


#endif /* class_h */
