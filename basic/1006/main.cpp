/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/28
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>

using namespace std;

int countd(long num,int d)
{

    int cnt = 0;
    while(num > 0)
    {
        if(num % 10 == d)
            cnt++;
        num /= 10;
    }
    return cnt;

}

long createNum(int d,int cnt)
{
    long sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        sum *= 10;
        sum += d;
    }

    return sum;

}

int main()
{
    int a,da,b,db;
    int cnta,cntb;
    cin>>a>>da>>b>>db;
    cnta = countd(a,da);
    cntb = countd(b,db);
    cout<<createNum(da,cnta) + createNum(db,cntb)<<endl;
}
