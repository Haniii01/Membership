//
//  readFIle.cpp
//  Membership
//
//  Created by cappuccino  on 2021/7/17.
//

#include "readFIle.hpp"
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(CONSUME_FILE, ios::in);
    
    string name;
    string sex;
    string bir;
    string passwd;
    string cum;
    string grade;
    string balance;
    
    size = 0;
    
    while (ifs >> name && ifs >> sex && ifs >> bir && ifs >> passwd && ifs >> cum && ifs >> grade && ifs >> balance) {
//        cout << grade << endl;
//        cout << discount << endl;
//        cout << endl;
        
        string key;
        string value;
        map<string, string> m;

        int pos = name.find(":");
        if(pos != -1)
        {
            key = name.substr(0, pos);
            value = name.substr(pos+1, name.size());

            m.insert(make_pair(key, value));
        }

        pos = sex.find(":");
        if(pos != -1)
        {
            key = sex.substr(0, pos);
            value = sex.substr(pos+1, sex.size());

            m.insert(make_pair(key, value));
        }

        pos = bir.find(":");
        if(pos != -1)
        {
            key = bir.substr(0, pos);
            value = bir.substr(pos+1, bir.size());

            m.insert(make_pair(key, value));
        }
        
        pos = passwd.find(":");
        if(pos != -1)
        {
            key = passwd.substr(0, pos);
            value = passwd.substr(pos+1, passwd.size());

            m.insert(make_pair(key, value));
        }

        pos = cum.find(":");
        if(pos != -1)
        {
            key = cum.substr(0, pos);
            value = cum.substr(pos+1, cum.size());

            m.insert(make_pair(key, value));
        }

        pos = grade.find(":");
        if(pos != -1)
        {
            key = grade.substr(0, pos);
            value = grade.substr(pos+1, grade.size());

            m.insert(make_pair(key, value));
        }

        pos = balance.find(":");
        if(pos != -1)
        {
            key = balance.substr(0, pos);
            value = balance.substr(pos+1, balance.size());

            m.insert(make_pair(key, value));
        }

        //将小map容器放入大map容器中
        orderData.insert(make_pair(size, m));
        size++;
    }
    ifs.close();
}

//更新预约记录
void OrderFile::updateOrder()
{
    if(size == 0)
    {
        return;
    }
    ofstream ofs(CONSUME_FILE, ios::out | ios:: trunc);
    for (int i = 0; i < size; i++) {
        ofs << "name:" << orderData[i]["name"] << " ";
        ofs << "sex:" << orderData[i]["sex"] << " ";
        ofs << "bir:" << orderData[i]["bir"] << " ";
        ofs << "passwd:" << orderData[i]["passwd"] << " ";
        ofs << "cum:" << orderData[i]["cum"] << " ";
        ofs << "grade:" << orderData[i]["grade"] << " ";
        ofs << "balance:" << orderData[i]["balance"] << endl;
    }
    ofs.close();
}

//记录所有信息的容器，key记录条数，value记录具体的键值对信息
map<int, map<string,string>> orderData;
