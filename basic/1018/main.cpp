/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/16
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

struct person
{
    string name;
    int yy;
    int mm;
    int dd;
    person(string n,int y,int m,int d)
    {
        name = n;
        yy = y;
        mm = m;
        dd = d;
    }

};

bool operator < (person p1,person p2)
{
    if((p1.yy<p2.yy)||((p1.yy==p2.yy)&&(p1.mm<p2.mm))||((p1.yy==p2.yy)&&(p1.mm==p2.mm)&&(p1.dd<p2.dd)))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int str2int(string str)
{
    int ans;
    istringstream is(str);
    is>>ans;
    return ans;
}

int parsebirth(string b,int &y,int &m,int &d)
{
    int p1,p2;
    p1 = b.find('/');
    if(p1 == string::npos)
        return -1;
    y = str2int(b.substr(0,p1));
    string m_d = b.substr(p1+1,b.length()-p1-1);
    p2 = m_d.find('/');
    if(p2 == string::npos)
        return -1;
    m = str2int(m_d.substr(0,p2));
    d = str2int(m_d.substr(p2+1,m_d.length()-p2-1));
    return 0;
}

bool check_valid(person p)
{
    if(person("",2014,9,6)<p)
    {
        return false;
    }
    if((2014-p.yy > 200)||((2014-p.yy==200)&&(9-p.mm>0))||((2014-p.yy==200)&&(9-p.mm==0)&&(6-p.dd>0)))
    {
        return false;
    }
    return true;
}

int main()
{
    int N;
    cin>>N;
    string name,birth;
    int y,m,d;
    vector<person> ps;
    for(int i = 0;i < N;i++)
    {
        cin>>name>>birth;
        if(0 == parsebirth(birth,y,m,d))
        {
            person tmp(name,y,m,d);
            if(check_valid(tmp))
            {
                ps.push_back(tmp);
            }
        }

    }
    sort(ps.begin(),ps.end());
    cout<<ps.size()<<" "<<ps.back().name<<" "<<ps.front().name<<endl;

}
