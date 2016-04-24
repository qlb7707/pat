/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/05
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

bool nless(int a,int b)
{
    if(a < b)
        return false;
    else
        return true;
}

vector<int> ntodigits(int n)
{
    vector<int> ans;
    for(int i = 0; i< 4;i++)
    {
        ans.push_back(n%10);
        n /= 10;
    }
    return ans;
}

int digitston(vector<int> digits)
{
    int sum = 0;
    int n = digits.size();
    for(int i = 0; i < n; i++)
    {
        sum *= 10;
        sum += digits[i];
    }
    return sum;
}

int main()
{
    int input;
    cin>>input;
    int ans;
    vector<int> digitsl(4),digitss(4);
    do
    {
        digitsl = ntodigits(input);
        digitss = digitsl;
        sort(digitsl.begin(),digitsl.end(),nless);
        sort(digitss.begin(),digitss.end());
        int max = digitston(digitsl);
        int min = digitston(digitss);
        ans = max - min;
        cout<<setfill('0')<<setw(4)<<max<<" - "<<setfill('0')<<setw(4)<<min<<" = "<<setfill('0')<<setw(4)<<ans<<endl;
        input = ans;

    }while(ans != 6174 && ans != 0);
    return 0;
    
}
