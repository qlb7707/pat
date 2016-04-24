/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/16
*   mail         :qin_libin@foxmail.com
*
================================================================*/


#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


int main()
{
    int N;
    cin>>N;
    int sc,gr;
    map<int,int> sc_gr;
    int mxsc = 0,mxgr = 0;
    for(int i = 0; i < N; i++)
    {
        cin>>sc>>gr;
        if(sc_gr.find(sc) == sc_gr.end())
        {
            sc_gr[sc] = gr;
        }
        else
        {
            sc_gr[sc] += gr;
        }
    }

    for(map<int,int>::iterator it = sc_gr.begin();it != sc_gr.end(); it++)
    {
        if(it->second > mxgr)
        {
            mxsc = it->first;
            mxgr = it->second;
        }
    }
    cout<<mxsc<<" "<<mxgr<<endl;

}
