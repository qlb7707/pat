/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/23
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "main.h"

#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int T;
    long A,B,C;
    cin >> T;
    vector<bool> ans;
    for(int i = 0;i < T;i++)
    {
        cin>>A>>B>>C;
        ans.push_back((A+B)>C);
    }

    for(int i = 0;i < T;i++)
    {
        if(ans[i]==true)
            cout<<"Case #"<<i+1<<":"<<"true"<<endl;
        else
            cout<<"Case #"<<i+1<<":"<<"false"<<endl;

    }
    return 0;
}
