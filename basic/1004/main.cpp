/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/26
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main()
{
    const char *day[7] = {"Mon","Tue","Wen","Thu","Fri","Sat","Sun"};
    string str1,str2,str3,str4;

    cin>>str1>>str2>>str3>>str4;

    vector<char> same1;
    int same2;
    int n1 = min(str1.size(),str2.size());
    int n2 = min(str3.size(),str4.size());
    
    int i;
    for(i = 0;i < n1;i++)
    {
        if(str1[i]<='Z'&&str1[i] >= 'A' && str1[i] == str2[i])
        {
            same1.push_back(str1[i]);
            break;
        }
    }
    for(i = i+1;i < n1; i++)
    {
        if(str1[i]==str2[i]&&(str1[i] >= 'A' && str1[i] <= 'N' || str1[i] >= '0' && str1[i] <= '9'))
        {
            same1.push_back(str1[i]);
            break;
        }
    }

    for(i = 0;i < n2; i++)
    {
        if(str3[i]==str4[i]&&(str3[i]>='a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z'))
        {
            same2 = i;
            break;
        }
    }

    cout<<day[same1[0]-'A']<<" ";
    if(same1[1] <= '9' && same1[1] >= '0')
        cout<<setfill('0')<<setw(2)<<int(same1[1]-'0')<<":";
    else
        cout<<setfill('0')<<setw(2)<<int(same1[1]- 'A' + 10)<<":";
    cout<<setfill('0')<<setw(2)<<same2<<endl;



    return 0;
}
