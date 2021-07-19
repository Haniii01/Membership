//
//  main.cpp
//  Membership
//
//  Created by cappuccino  on 2021/7/16.
//

#include <iostream>
#include <fstream>
#include "class.h"
#include "Consume.hpp"
using namespace std;

void consumeMenu(Users * &consume)
{
    while (true) {
        //调用子菜单界面
        consume -> operMenu();
        
        Consume * con = (Consume*) consume;
        
        int select = 0;
        while (true) {
            cin >> select;
            if (select == 1) {
                con -> shoppingSpending();
                break;
            }
            else if(select == 2)
            {
                con -> showAllServices();
                break;
            }
            else if(select == 0)
            {
                delete con;
                cout << "注销成功" << endl;
                printf("press any key to continue......\n");
                getchar();
                return;
            }
            else
            {
                cout << "输入错误，请重新输入：" << endl;
            }
        }

    };
}

void LoginIn(string filename, int type)
{
    Users * person;
    
    //读文件
    ifstream ifs;
    ifs.open(filename,ios::in);
    
    //判断文件是否存在
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    
    string name;
    string sex;
    string bir;
    int passwd;
    double con;
    string grade;
    double balance;
    
        
    cout << "请输入你的昵称：" << endl;
    cin >> name;
    
//    cout << "请输入性别" << endl;
//    cin >> sex;
//    
//    cout << "请输入生日" << endl;
//    cin >> bir;
    
    cout << "请输入密码" << endl;
    cin >> passwd;
    
    
    if (type == 1)//学生身份验证
    {
        string fName;
        string fSex;
        string fBir;
        int fPasswd;
        string fpasswd;
        
        float fCon;
        string fcon;
        
        string fGrade;
        
        float fBalance;
        string fbalance;
        while(ifs >> fName && ifs >> fSex && ifs >> fBir && ifs >> fpasswd && ifs >> fcon && ifs >> fGrade && ifs >> fbalance)
        {
//            cout << fName << endl;
//            cout << fSex << endl;
//            cout << fBir << endl;
//            cout << fpasswd << endl;
//            cout << fcon << endl;
//            cout << fGrade << endl;
//            cout << fbalance << endl;
            fPasswd = atoi(fpasswd.c_str());
           if(fName == name && fPasswd == passwd)
           {
               fCon = atof(fcon.c_str());
               fBalance = atof(fbalance.c_str());
               con = fCon;
               grade = fGrade;
               balance = fBalance;
               bir = fBir;
               cout << "验证登录成功!" << endl;
//               printf("press any key to continue......\n");
//               getchar();
               person = new Consume(name, sex, bir, passwd, con, grade, balance);
               //进入学生身份子菜单
               consumeMenu(person);
               return;
           }
        }
    }
}

int main() {
    LoginIn(TEST_FILE, 1);
    return 0;
}
