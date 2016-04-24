/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/09
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
using namespace std;

void get_value(vector<char> &src,int n_exp,bool sig_val,bool sig_exp)
{
    int dot_point = 1;
    if(sig_exp)
    {
        dot_point += n_exp;
    }
    else
    {
        while(n_exp)
        {
            src.insert(src.begin(),'0');
            n_exp--;
        }
    }
    if(dot_point < src.size())
    {
        src.insert(src.begin()+dot_point,'.');
    }
    else
    {
        int npad = dot_point - src.size();
        for(int i = 0; i < npad; i++)
        {
            src.insert(src.end(),'0');
        }
    }
    if(!sig_val)
    {
        src.insert(src.begin(),'-');
    }


}

int main()
{
    string input;
    cin>>input;
    vector<char> digits;
    bool sig_val,sig_exp;
    bool val_finish = false;
    int n = input.length();
    int n_exp = 0;
    if(input[0] == '+')
        sig_val = true;
    else
        sig_val = false;
    for(int i = 1; i < n; i++)
    {
        if((input[i] >= '0' && input[i] <= '9')  && !val_finish)
        {
            digits.push_back(input[i]);
        }
        else if((input[i] >= '0' && input[i] <= '9') && val_finish)
        {
            n_exp *= 10;
            n_exp += input[i] - '0';
        }     
        else if(input[i] == '.')
        {
            continue;
        }
        else if(input[i] == 'E')
        {
            val_finish = true;
        }
        else if(input[i] == '+')
        {
            sig_exp = true;
        }
        else
        {
            sig_exp = false;
        }
    }
    get_value(digits,n_exp,sig_val,sig_exp);
    int n2 = digits.size();
    for(int i = 0;i < n2; i++)
    {
        cout<<digits[i];
    }
    cout<<endl;

}

