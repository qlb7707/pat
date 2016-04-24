/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/07
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string input;
    cin>>input;
    vector<int> dig_cnt(10,0);
    int n = input.length();
    for(int i = 0; i < n; i++)
    {
        dig_cnt[input[i] - '0'] ++;
    }
    for(int i = 0;i < 10; i++)
    {
        if(dig_cnt[i])
            cout<<i<<":"<<dig_cnt[i]<<endl;
    }
}
