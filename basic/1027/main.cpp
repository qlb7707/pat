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
#include<sstream>
using namespace std;

int str2int(string s)
{
    int ans;
    istringstream is(s);
    is>>ans;
    return ans;
}

void parse(string s ,int& a,int& b,int& c)
{
    int p1,p2;
    p1 = s.find('.');
    a = str2int(s.substr(0,p1));
    string sk = s.substr(p1+1,s.length() - p1 - 1);
    p2 = sk.find('.');
    b = str2int(sk.substr(0,p2));
    c = str2int(sk.substr(p2+1,sk.length()- p2 -1));
}

int main()
{
   int pg,ps,pk;
   int ag,as,ak;
   int ansg,anss,ansk;
   bool minus = false;
   string p,a;
   cin>>p>>a;
   parse(p,pg,ps,pk);
   parse(a,ag,as,ak);
   int psum = pk + ps * 29 + pg * 29 * 17;
   int asum = ak + as * 29 + ag * 29 * 17;
   int charge = asum - psum;
   if(charge < 0)
   {
       minus = true;
   }

   ansk = charge % 29;
   charge /= 29;
   anss = charge % 17;
   charge /= 17;
   ansg = charge;
   if(!minus)
       cout<<ansg<<"."<<anss<<"."<<ansk<<endl;
   else
       cout<<"-"<<ansg * (-1)<<"."<<anss * (-1)<<"."<<ansk * (-1)<<endl;

}
