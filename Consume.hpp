//
//  Consume.hpp
//  Membership
//
//  Created by cappuccino  on 2021/7/16.
//

#ifndef Consume_hpp
#define Consume_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "class.h"
#include "globalFile.h"
#include "gradeOfVip.hpp"
#include "readFIle.hpp"
using namespace std;
class Consume:public Users
{
protected:
    
public:
    //默认构造
    Consume(){};
    //有参构造
    Consume(string na, string se, string bi, int pa);
    Consume(string na, string se, string bi, int pa,double c,string gr,double b);
    //菜单界面
    void operMenu();
    //消费金额
    void shoppingSpending();
    //查看所有优惠
    void showAllServices();
    ~Consume(){}
    //等级容器
    vector<gradeOfVip> vGrad;
    //初始化容器
    void initVector();
};

#endif /* Consume_hpp */
