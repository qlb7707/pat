/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/24
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<cmath>
using namespace std;

long nextprime(long prime)
{
    if(prime < 2 && prime > 0)
        return 2;
    long next = prime + 1;
    while(1)
    {
        long term = sqrt(next);
        long i;
        for(i = 2; i<= term; i++)
        {
            if(next % i == 0)
                break;
        }
        if(i > term)
            break;
        next++;
    }
    return next;
}

int main()
{
    int m,n;
    cin>>m>>n;
    long pm=1;
    if(m > n)
        return -1;
    for(int i = 0; i< m-1;i++)
    {
        pm = nextprime(pm);
    }
    for(int i = m; i<= n; i++)
    {
        pm = nextprime(pm);
        if(i != n && (i-m)%10 != 9)
        {
            cout<<pm<<" ";
        }
        else
            cout<<pm<<endl;
        
    }
    return 0;
}
