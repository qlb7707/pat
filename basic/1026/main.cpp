/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/18
*   mail         :qin_libin@foxmail.com
*
================================================================*/


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    char c;
    cin>>N>>c;
    double height = N/2.0;
    int h = int(height + 0.5);
    for(int i = 0 ; i<h;i++)
    {
        if(i == 0 || i == h - 1)
        {
            for(int i = 0;i<N;i++)
            {
                cout<<c;
            }
            cout<<endl;
        }
        else
        {
            cout<<c;
            for(int i = 1; i < N-1;i++)
            {
                cout<<" ";
            }
            cout<<c<<endl;
        }
    }
    

}
