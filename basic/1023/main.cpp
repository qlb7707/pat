/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/17
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
using namespace std;

int main()
{
    string broken;
    string str;
    string out;
    cin>>broken>>str;
    bool shift = false;
    if(broken.find('+')!=string::npos)
        shift = true;
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        if(broken.find(str[i]) != string::npos)
            continue;
        if(str[i]>='a' && str[i] <= 'z')
        {
            if(broken.find(str[i] - ('a' - 'A')) != string::npos)
            {
                continue;
            }
            else
            {
                out += str[i];
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if(shift)
            {
               continue;// out += str[i]+'a'-'A';
            }
            else
            {
                out += str[i];
            }
        }
        else
        {
            out += str[i];
        }
    }

    cout<<out<<endl;


}
