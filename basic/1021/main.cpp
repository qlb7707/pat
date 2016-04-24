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
using namespace std;


bool check_valid(string s,string map,int w[])
{
    //check all numbers
    int sum = 0;
    char M;
    for(int i = 0; i < 17; i++)
    {
        if(!(s[i]>='0'&&s[i]<='9'))
        {
            return false;
        }
        sum += (s[i] - '0')*w[i];
    }
    M =map[sum % 11];
    if(M!=s[17])
        return false;
    return true;
}

int main()
{
    int N;
    cin>>N;
    vector<string> ids;
    string map = "10X98765432";
    int w[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    for(int i = 0 ;i < N; i++)
    {
        string str;
        cin>>str;
        if(!check_valid(str,map,w))
            ids.push_back(str);
    }

    if(ids.empty())
        cout<<"All passed"<<endl;
    else
    {
        for(int i = 0; i < ids.size(); i++)
            cout<<ids[i]<<endl;
    }


}
