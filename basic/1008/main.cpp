/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/04
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
using namespace std;

void myprint(vector<int> wins)
{
    int mx = 0;
    string p[3] = {"B","C","J"};
    vector<char> ans;
    for(int i = 0;i < wins.size(); i++)
    {
        if(mx < wins[i])
            mx = wins[i];
    }
    for(int i = 0;i < wins.size(); i++)
    {
        if(wins[i] == mx)
        {
            cout<<p[i];
            break;
        }
    }


}

int compair(char a,char b)
{
    if(a == 'C' && b == 'B' || a == 'B' && b == 'J' || a == 'J' && b == 'C')
        return -1;
    else if(a == 'B' && b == 'C' || a == 'J' && b == 'B' || a == 'C' && b == 'J')
        return 1;
    else
        return 0;
        
}

int main()
{
    int n;
    cin>>n;
    char a,b;
    int awn=0,bwn=0,neq=0;
    vector<int> awins(3,0);
    vector<int> bwins(3,0);
    
    for(int i = 0;i < n;i ++)
    {
        cin>>a>>b;
        if(compair(a,b) == 1)
        {
            awn++;
            if(a == 'B')
                awins[0]++;
            else if(a == 'C')
                awins[1]++;
            else
                awins[2]++;
        }
        else if(compair(a,b) == -1)
        {
            bwn++;
            if(b == 'B')
                bwins[0]++;
            else if(b == 'C')
                bwins[1]++;
            else
                bwins[2]++;

        }
        else
        {
            neq++;
            continue;
        }
    }
    cout<<awn<<" "<<neq<<" "<<bwn<<endl;
    cout<<bwn<<" "<<neq<<" "<<awn<<endl;
    myprint(awins);
    cout<<" ";
    myprint(bwins);
    cout<<endl;
}
