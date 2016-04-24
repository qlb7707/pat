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
#include<vector>
#include<set>
using namespace std;


int main()
{
    string in,out;
    string broken;
    cin>>in>>out;
    int n = in.length();
    for(int i = 0; i < n;i++)
    {
        if(in[i]>='A' && in[i]<= 'Z')
        {
            int p1 = out.find(in[i]);
            int p2 = out.find(in[i]+'a'-'A');
            if(p1==string::npos && p2 == string::npos)
            {
                if(broken.find(in[i]) == string::npos)
                {
                    broken += in[i];
                }
            }
        }
        else if(in[i]>='a' && in[i] <= 'z')
        {
            int p1 = out.find(in[i]);
            int p2 = out.find(in[i]-('a'-'A'));
            if(p1 == string::npos && p2 == string::npos)
            {
                if(broken.find(in[i]-('a'-'A')) == string::npos)
                {
                    broken += in[i] - ('a' - 'A');
                }
            }
        }
        else
        {
            int p = out.find(in[i]);
            if(p == string::npos)
            {
                if(broken.find(in[i]) == string::npos)
                {
                    broken += in[i];
                }
            }
        }

    }
    int nb = broken.length();
    for(int i = 0;i < nb;i++)
    {
        cout<<broken[i];
    }
    cout<<endl;

}
