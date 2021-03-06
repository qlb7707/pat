/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/04
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "main.h"
//
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string str;
    int n;
    cin>>str>>n;
    string ans;
    int mod = 0;
    int len = str.length();
    for(int i = 0; i < len;i++)
    {
        if((str[i]-'0' + mod*10) >= n)
        {
            ans += (str[i] - '0' + mod*10) / n + '0';
            mod = (str[i] - '0' + mod*10) % n;
        }
        else
        {
	    if(!ans.empty())
		ans += '0';
            mod = str[i] - '0' + mod * 10;
        }
    }

    cout<<ans<<" "<<mod<<endl;
}
