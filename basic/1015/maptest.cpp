/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :maptest.cpp
*   author       :qinlibin
*   create date  :2016/04/23
*   mail         :qin_libin@foxmail.com
*
================================================================*/
#include<iostream>
#include<map>
using namespace std;

struct Node
{
    int a;
    int b;
    Node(int aa,int bb)
    {
        a = aa;
        b = bb;

    }
    Node()
    {
        a=0;
        b=0;
    }
};
int main()
{
    map<string,Node> mp;
    mp["1"] = Node(1,1);
    mp["2"] = Node(2,2);
    cout<<mp["1"].a<<" "<<mp["2"].b<<endl;
    return 0;

}
