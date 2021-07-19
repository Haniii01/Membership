//
//  gradeOfVip.hpp
//  Membership
//
//  Created by cappuccino  on 2021/7/17.
//

#ifndef gradeOfVip_hpp
#define gradeOfVip_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
//查看所有优惠
class gradeOfVip
{
public:
    string Grade;
    int Discount;
    gradeOfVip(){
        Grade = "";
        Discount = 0;
    }
    gradeOfVip(string grade, int discount)
    {
        Grade = grade;
        Discount = discount;
    }
};
#endif /* gradeOfVip_hpp */
