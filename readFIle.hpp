//
//  readFIle.hpp
//  Membership
//
//  Created by cappuccino  on 2021/7/17.
//

#ifndef readFIle_hpp
#define readFIle_hpp

#include <stdio.h>
#include <iostream>
#pragma once
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile
{
public:
    //构造函数
    OrderFile();
    
    //更新预约记录
    void updateOrder();
    
    //更新预约条数
    int size;
    
    //记录所有预约信息的容器，key记录条数，value记录具体的键值对信息
    map<int, map<string,string>> orderData;
};


#endif /* readFIle_hpp */
