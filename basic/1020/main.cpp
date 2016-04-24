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
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    vector<int> nums;
    int n,p;
    int num;
    cin>>n>>p;
    bool found = false;
    for(int i = 0; i < n; i++)
    {
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    int sz = n;
    while(!found)
    {
        for(int i = 0;i < n - sz +1; i++)
        {
            if(nums[i+sz-1] < p*nums[i])
            {
                found = true;
                break;
            }
        }
        if(found)
            break;
        sz --;
    }

    cout << sz<<endl;
    



}
