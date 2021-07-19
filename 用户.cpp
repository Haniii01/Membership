#include<iostream>
#include<string>
#include"class.h"
using namespace std;
//”√ªß¿‡∫Ø ˝
    Users::Users(string na, string se, string bi, int pa) :name(na), sex(se), bir(bi), passwd(pa) {
        cum = 0;
        grade = "vip";
        balance = 0;
    }
    Users::Users(string na, string se, string bi, int pa, double c, string gr, double b): name(na), sex(se), bir(bi), passwd(pa),cum(c),grade(gr),balance(b){}
    string Users::getname()
    {
        return name;
    }
    string Users::getsex()
    {
        return sex;
    }
    string Users::getbirth()
    {
        return bir;
    }
    int Users::getpasswd()
    {
        return passwd;
    }
    double Users::getcum() {
        return cum;
    }
    string Users::getgrade() {
        return grade;
    }
    double Users::getbalance() {
        return balance;
    }
    void Users::setbalance(double m) {
        balance += m;
    }
    void Users::setgrade(string m) {
        grade = m;
  }
