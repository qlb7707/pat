/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/20
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
using namespace std;

int main()
{
    string input;
    cin>>input;
    long sum;
    int sz = input.size();
    int prep[100000]={0};
    int postt[100000]={0};
    for(int i = 0;i < sz-1; i++)
    {
        if(input[i] == 'P')
        {
            prep[i+1] = prep[i] + 1;
        }
        else
        {
            prep[i+1] = prep[i];
        }
    }

    for(int i = sz-1; i >=1; i--)
    {
        if(input[i] == 'T')
        {
            postt[i-1] = postt[i] + 1;
        }
        else
        {
            postt[i-1] = postt[i];
        }
    }

    for(int i = 0; i < sz; i++)
    {
        if(input[i] == 'A')
        {
            sum += prep[i] * postt[i];
        }
    }
    cout<<sum<<endl;

}
