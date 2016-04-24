/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/20
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>

using namespace std;

int main()
{
    string have,want;
    cin>>have>>want;
    int lack = 0;
    int left = 0;
    int nums[128] = {0};
    int nh,nw;
    nh = have.size();
    nw = want.size();
    for(int i = 0;i < nh; i++)
    {
        nums[int(have[i])]++;
    }

    for(int i = 0;i < nw; i++)
    {
        nums[want[i]] --;
    }

    for(int i = 0; i < 128; i++)
    {
        left += nums[i];
        if(nums[i] < 0)
        {
            lack -= nums[i];
        }
    }
    if(lack)
    {
        cout<<"No "<<lack<<endl;
    }
    else
    {
        cout<<"Yes "<<left<<endl;
    }
}
