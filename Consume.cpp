//
//  Consume.cpp
//  Membership
//
//  Created by cappuccino  on 2021/7/16.
//

#include "Consume.hpp"
//默认构造
Consume::Consume(string na, string se, string bi, int pa)
:Users(na, se, bi, pa)
{
    cum = 0;
    grade = "vip";
    balance = 0;
}
//有参构造 学号、姓名、密码
Consume::Consume(string na, string se, string bi, int pa,double c,string gr,double b)
:Users( na,  se,  bi,  pa, c, gr, b)
{
}
//菜单界面
void Consume::operMenu()
{
    cout << "欢迎：" << name << "登录" << endl;
    cout << "\t\t  ---------------------------------\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |            1.开始消费            |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |            2.查看优惠           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |            0.注销登录            |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t  ---------------------------------\n";
    cout << "请输入您的操作：";
}
//消费
void Consume::shoppingSpending()
{
    cout << "请输入消费时间" << endl;
    
    string date = "";//日期
    double money = 0;//时间段
    
    while (true) {
        cin >> date;
        if (date != "") {
            break;
        }
        else
            cout << "输入有误，请重新输入" << endl;
        
    };
    cout << "请输入消费金额：" << endl;
    
    while(true)
    {
        cin >> money;
        if(money >= 0.0)
        {
            break;
        }
        cout << "输入有误，请重新输入"  << endl;
    }
    
    OrderFile of;
    if(of.size == 0)
    {
        cout << "无预约记录！" << endl;
        printf("press any key to continue......\n");
        getchar();
        return;
    }
    
    vector<int>v;
    for (int i = 0; i < of.size; i++) {
        if (of.orderData[i]["name"] == name) {
            v.push_back(i);
            cout << "您的会员等级为：" << of.orderData[i]["grade"] <<" ";
//            cout << "生日为：" << of.orderData[i]["bir"] << " ";
            cout << "您的累积消费为" << of.orderData[i]["cum"] << " ";
            cout << "您的余额为" << of.orderData[i]["balance"] << endl;
            if(of.orderData[i]["name"] == name && of.orderData[i]["bir"] == date)
            {
                cout << "今天是您的生日" << endl;
                cout << "所有的烦恼说拜拜，所有的快乐说嗨嗨" << endl;
                cout << "衷心祝福您，生日快乐" << endl;
                cout << "您今天购物会享受六折" << endl;
                money *= 0.6;
                cout << "现在您需要付款：" << money << "元" << endl;
                cout << "您要选择余额付款还是直接支付？" << endl;
                cout << "请输入1.余额付款 2.直接支付" << endl;
                int ret = 0;//接收预约结果记录
                
                while (true) {
                    cin >> ret;
                    if(ret == 1)
                    {
                        cout << "您的余额为" << of.orderData[i]["balance"] << endl;
                        if(atof(of.orderData[i]["balance"].c_str()) > money)
                        {
                            cout << "支付成功" << endl;
                            of.orderData[i]["balance"] = to_string(atof(of.orderData[i]["balance"].c_str()) - money);
                            cout << "现在您的余额为：" << of.orderData[i]["balance"] << endl;
                            cout << "已更新累积消费" << endl;
                            of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                            cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                            printf("press any key to continue......\n");
                            getchar();
                            of.updateOrder();
                            return;
                        }
                        else
                        {
                            of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                            money -= atof(of.orderData[i]["balance"].c_str());
                            cout << "您的余额不足，您还需支付：" << money << "元" << endl;
                            cout << "请输入您支付的金额（如果多于待支付金额将存入余额）：" << endl;
                            double pay;
                            while (true) {
                                cin >> pay;
                                if (pay >= money) {
                                    of.orderData[i]["balance"] = to_string(pay - money);
                                    break;
                                }
                                else
                                {
                                    money -= pay;
                                    cout << "您还需支付："<< money << "元" << endl;
                                }
                            }
                            cout << "支付成功" << endl;
                            cout << "已更新累积消费" << endl;
                            cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                            printf("press any key to continue......\n");
                            getchar();
                            of.updateOrder();
                            return;
                        }
                    }
                    else if(ret == 2)
                    {
                        cout << "请输入您支付的金额（如果多于待支付金额将存入余额）：" << endl;
                        double pay;
                        while (true) {
                            cin >> pay;
                            if (pay >= money) {
                                of.orderData[i]["balance"] = to_string(pay - money);
                                break;
                            }
                            else
                            {
                                money -= pay;
                                cout << "您还需支付："<< money << "元" << endl;
                            }
                        }
                        cout << "支付成功" << endl;
                        cout << "已更新累积消费" << endl;
                        of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                        cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                        printf("press any key to continue......\n");
                        getchar();
                        of.updateOrder();
                        return;
                    }
                    else
                    {
                        cout << "输入有误，请重新输入" << endl;
                    }
                }
            }
            else
            {
                string str;
                if(of.orderData[i]["grade"] == "vip")
                {
                    str = "九折";
                    money *= 0.9;
                }
                else if(of.orderData[i]["grade"] == "svip")
                {
                    str = "八折";
                    money *= 0.8;
                }
                else if(of.orderData[i]["grade"] == "ssvip")
                {
                    str = "六折";
                    money *= 0.6;
                }
                cout << "您购物会享受" << str << "优惠" << endl;
                cout << "现在您需要付款：" << money << "元" << endl;
                cout << "您要选择余额付款还是直接支付？" << endl;
                cout << "请输入1.余额付款 2.直接支付" << endl;
                int ret = 0;//接收预约结果记录
                    
                    while (true) {
                        cin >> ret;
                        if(ret == 1)
                        {
                            cout << "您的余额为" << of.orderData[i]["balance"] << endl;
                            if(atof(of.orderData[i]["balance"].c_str()) > money)
                            {
                                cout << "支付成功" << endl;
                                of.orderData[i]["balance"] = to_string(atof(of.orderData[i]["balance"].c_str()) - money);
                                cout << "现在您的余额为：" << of.orderData[i]["balance"] << endl;
                                cout << "已更新累积消费" << endl;
                                of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                                cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                                printf("press any key to continue......\n");
                                getchar();
                                of.updateOrder();
                                return;
                            }
                            else
                            {
                                of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                                of.orderData[i]["balance"] = "0";
                                money -= atof(of.orderData[i]["balance"].c_str());
                                cout << "您的余额不足，您还需支付：" << money << "元" << endl;
                                cout << "请输入您支付的金额（如果多于待支付金额将存入余额）：" << endl;
                                double pay;
                                while (true) {
                                    cin >> pay;
                                    if (pay >= money) {
                                        of.orderData[i]["balance"] = to_string(pay - money);
                                        break;
                                    }
                                    else
                                    {
                                        money -= pay;
                                        cout << "您还需支付："<< money << "元" << endl;
                                    }
                                }
                                cout << "支付成功" << endl;
                                cout << "已更新累积消费" << endl;
                                cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                                printf("press any key to continue......\n");
                                getchar();
                                of.updateOrder();
                                return;
                            }
                        }
                        else if(ret == 2)
                        {
                            cout << "请输入您支付的金额（如果多于待支付金额将存入余额）：" << endl;
                            double pay;
                            while (true) {
                                cin >> pay;
                                if (pay >= money) {
                                    of.orderData[i]["balance"] = to_string(pay - money);
                                    break;
                                }
                                else
                                {
                                    money -= pay;
                                    cout << "您还需支付："<< money << "元" << endl;
                                }
                            }
                            cout << "支付成功" << endl;
                            cout << "已更新累积消费" << endl;
                            of.orderData[i]["cum"] = to_string(atof(of.orderData[i]["cum"].c_str()) + money);
                            cout << "您现在的累积消费为：" << of.orderData[i]["cum"];
                            printf("press any key to continue......\n");
                            getchar();
                            of.updateOrder();
                            return;
                        }
                        else
                        {
                            cout << "输入有误，请重新输入" << endl;
                        }
                
                printf("press any key to continue......\n");
                getchar();
                return;
                    }
            }
        }
        
    }
    
}
//查看所有优惠
void Consume::showAllServices()
{
    //初始化机房信息
    ifstream ifs;
    ifs.open(VIP_FILE, ios::in);
    
    gradeOfVip grad;
    while (ifs >> grad.Grade && ifs >> grad.Discount) {
        //将读取信息放入容器中
        vGrad.push_back(grad);
    }
    ifs.close();
    for (vector<gradeOfVip>::iterator it = vGrad.begin(); it != vGrad.end(); it++)
    {
            cout<< "当您的等级为：" << (*it).Grade << "时,我们的打折力度为："  << (*it).Discount << "\%" << endl;
    }
    
    printf("press any key to continue......\n");
    getchar();
    
    return;
}
//等级容器
vector<Consume> vCon;
//初始化容器
void Consume::initVector()
{
    //确保容器清空
    vCon.clear();
    
    //读取信息
    ifstream ifs;
    ifs.open(CONSUME_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }
    
    Consume c;
    while (ifs >> c.name && ifs >> c.sex && ifs >> c.bir && ifs >> c.passwd && ifs >> c.cum && ifs >> c.grade && ifs >> c.balance) {
        vCon.push_back(c);
    }
//    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close();
    
}
