/*================================================================
*   Copyright (C) 2016 All rights reserved.
*  
*   filename     :main2.cpp
*   author       :qinlibin
*   create date  :2016/04/23
*   mail         :qin_libin@foxmail.com
*
================================================================*/
 
#include<iostream>
#include<map>
#include<vector>
using namespace std;
 
 
struct Node
{
    string addr;
    int val;
    string Next;
    Node(string ad,int v,string N)
    {
        addr = ad;
        val = v;
        Next = N;
    }
    Node()
    {
        addr="";
        val=0;
        Next="";
    }
};
 
map<string,Node> mp;
vector<Node> list;
vector<Node> fin;
 
int main()
{
   // map<string,Node> mp;
    string st;
    int num,k;
    cin>>st>>num>>k;
    string addr,Next;
    int val;
   // vector<Node> list;
   // vector<Node> fin;
    for(int i = 0; i < num;i++)
    {
        cin>>addr>>val>>Next;
        Node tmp(addr,val,Next);
        mp.insert(pair<string,Node>(addr,tmp));
    }
    while(st != "-1")
    {
        list.push_back(mp[st]);
        st = mp[st].Next;
    }
    int slow = 0,fast = k-1;
   while(fast<num)
    {
        for(int i = 0; i < k; i++)
        {
            Node tmp = list[fast - i];
            if(i != k-1)
            {
                tmp.Next = list[fast-1 - i].addr;
            }
            else if(fast + k >= num)
            {
                if(fast + 1 == num )
                    tmp.Next = "-1";
                else
                    tmp.Next = list[fast+1].addr;
            }
            else
            {
                tmp.Next = list[fast+k].addr;
            }
            fin.push_back(tmp);
        }
        fast += k;
    }
    int nf = fin.size();
    for(int i = 0; i < num - nf; i++)
    {
        fin.push_back(list[nf+i]);
    }
 
    for(int i = 0;i < num;i++)
    {
        cout<<fin[i].addr<<" "<<fin[i].val<<" "<<fin[i].Next<<endl;
    }
 
 
}


