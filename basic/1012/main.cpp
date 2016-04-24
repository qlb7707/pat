/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/09
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<deque>
using namespace std;

deque<int> demi2d(unsigned int a, unsigned int d)
{
    deque<int>ans;
    unsigned int div;
    int mod;
    while(a >= d)
    {
        div = a / d;
        mod = a % d;
        ans.push_front(mod);
        a = div;
    }
    if(a)
        ans.push_front(a);
    return ans;
}

int main()
{
    unsigned int num1,num2,d;
    deque<int> ans;
    cin>>num1>>num2>>d;
    ans = demi2d(num1 + num2,d);
    for(int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i];
    }
    cout<<endl;
}

