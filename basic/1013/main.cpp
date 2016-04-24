/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/09
*   mail         :qin_libin@foxmail.com
*
===============================================================*/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int idx;
    int num;
    node(int i,int n)
    {
        idx = i;
        num = n;
    }
};

int main()
{
    vector<node> numbers;
    int num;
    vector<int> ans;
    for(int i = 0; i < 10; i++)
    {
        cin>>num;
        if(num)
            numbers.push_back(node(i,num));
    }

    if(numbers[0].idx == 0)
    {
        ans.push_back(numbers[1].idx);
        numbers[1].num--;
    }

    for(int i = 0; i < numbers.size();i++)
    {
        for(int j = 0; j < numbers[i].num;j++)
            ans.push_back(numbers[i].idx);
    }

    for(int i = 0 ;i < ans.size(); i++)
    {
        cout<<ans[i];
    }
    cout<<endl;



}
