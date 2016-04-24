/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main3.cpp
*   author       :qinlibin
*   create date  :2016/04/24
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>

using namespace std;

struct Node
{
    int addr;
    int val;
    int next;
    Node(int ad,int v,int n)
    {
        addr = ad;
        bal = v;
        next = n;
    }
};

int main()
{
    int st,num,k;
    cin>>st>>num>>k;
    int addr,val,next;
    int data[100000];
    int ordered[100000];
    int fin[100000]
    for(int i = 0; i < num; i++)
    {
        cin>>addr>>val>>next;
        Node tmp(addr,val,next);
        data[addr] = tmp;
    }
    int cnt = 0;
    while(st != -1)
    {
        ordered[cnt] = data[st];
        st = data[st].next;
    }
    int fin_num = 0;
    for(int fast = k-1; fast < cnt; fast += k)
    {
        for(int i = 0;i < k;i++)
        {
            fin[fin_num] = ordered[fast - i];
            fin_num ++;
        }
    }
    for(int i = fin_num; i < cnt;i++)
    {
        fin[fin_num] = order[fin_num];
        fin_num++;
    }
    for(int i = 0;i < cnt;i++)
    {
        if(i == cnt - 1)
        {
            cout<<fin[i].addr<<" "<<fin[i].val<<" "<<"-1"<<endl;
        }
        else
        {
            cout<<fin[i].addr<<" "<<fin[i].val<<" "<<fin[i+1].addr<<endl;
        }
    }


}
