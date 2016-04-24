/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/23
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int T;
    int a1=0,a2=0,a3=0,a5=0,a4_num=0;
    double a4 = 0;
    int p_n = 1,yu,num;
    cin>>T;
    for(int i = 0;i < T;i++)
    {
        cin>>num;
        yu = num % 5;
        switch(yu)
        {
            case 0:
                if(num % 2 == 0)
                {
                    a1 += num;
                }
                break;
            case 1:
                a2 += num*p_n;
                p_n *= -1;
                break;
            case 2:
                a3 ++;
                break;
            case 3:
                a4 += num;
                a4_num++;
                break;
            default:
                if( num > a5)
                {
                    a5 = num;

                }
        }
    }
    if(a1)
        cout<<a1<<" ";
    else
        cout<<"N ";
    if(a2)
        cout<<a2<<" ";
    else
        cout<<"N ";
    if(a3)
        cout<<a3<<" ";
    else
        cout<<"N ";
    if(a4)
        cout<<fixed<<setprecision(1)<<a4/a4_num<<" ";
    else
        cout<<"N ";
    if(a5)
        cout<<a5<<" "<<endl;
    else
        cout<<"N"<<endl;

}
