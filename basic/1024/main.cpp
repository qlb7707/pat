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
#include<sstream>
#include<cmath>
using namespace std;

bool div_0 = false;
int gcd(int a,int b)
{
    if(a % b == 0)
        return b;
    else
        return gcd(b,a%b);
}

int str2int(string str)
{
    istringstream is(str);
    int ans;
    is>>ans;
    return ans;
}

int parseint(string num,int &nu,int &de)
{
    int p1;
    p1 = num.find('/');
    if(p1 == string::npos)
        return -1;
    nu = str2int(num.substr(0,p1));
    de = str2int(num.substr(p1+1,num.length()-p1-1));
    return 0;
}

void print(int fake1,int nu1,int de1,int fake2,int nu2,int de2,int fakeans,int nuans,int deans,char c)
{
    if(fake1>0)
        cout<<fake1;
    if(fake1 < 0)
        cout<<"("<<fake1;
    if(nu1>0||nu1<0&&!fake1)
    {
        if(fake1)
            cout<<" ";
        cout<<nu1<<"/"<<de1<<" ";
    }
    if(nu1<0 && fake1)
        cout<<" "<<nu1*(-1)<<"/"<<de1<<") ";
    if(!nu1&&fake1<0)
        cout<<") ";
    if(!fake1&&!nu1)
        cout<<"0 ";
    cout<<c<<" ";
    if(fake2>0)
        cout<<fake2;
    if(fake2<0)
        cout<<"("<<fake2;
    if(nu2>0||nu2<0&&!fake2)
    {
        if(fake2)
            cout<<" ";
        cout<<nu2<<"/"<<de2<<" ";
    }
    if(nu2<0&&fake2)
        cout<<" "<<nu2*(-1)<<"/"<<de2<<") ";
    if(!nu2&&fake2<0)
        cout<<") ";
    if(!fake2&&!nu2)
        cout<<"0 ";
    cout<<"= ";
    
    if(c=='/' && div_0)
        cout<<"Inf"<<endl;
    else
    {
        if(fakeans>0)
            cout<<fakeans;
        if(fakeans<0)
            cout<<"("<<fakeans;
        if(nuans>0 || nuans<0 && !fakeans)
        {
            if(fakeans)
                cout<<" ";
            cout<<nuans<<"/"<<deans<<endl;
        }
        if(nuans<0 && fakeans)
            cout<<" "<<nuans*(-1)<<"/"<<deans<<")"<<endl;
        if(!nuans&&fakeans<0)
            cout<<")"<<endl;
        if(!fakeans&&!nuans)
            cout<<"0"<<endl;
    }

}

int main()
{
    string num1,num2;
    cin>>num1>>num2;
    int nu1,nu2,de1,de2;
    int fake1 = 0,fake2 = 0;
    int gcd1,gcd2;
    int nusum,desum,fakesum=0,gcdsum;
    int nusub,desub,fakesub=0,gcdsub;
    int numul,demul,fakemul=0,gcdmul;
    int nudiv,dediv,fakediv=0,gcddiv;
    parseint(num1,nu1,de1);
    parseint(num2,nu2,de2);
    cout<<nu1<<" "<<de1<<endl;
    cout<<nu2<<" "<<de2<<endl;
    if(abs(nu1) >= abs(de1))
    {
        fake1 = nu1 / de1;
        nu1 = nu1 % de1;
    }
    if(abs(nu2) >= abs(de2))
    {
        fake2 = nu2 / de2;
        nu2 = nu2 % de2;
    }
    gcd1 = gcd(nu1,de1);
    nu1 /= gcd1;
    de1 /= gcd1;
    
    gcd2 = gcd(nu2,de2);
    nu2 /= gcd2;
    de2 /= gcd2;

    nusum = (fake1 * de1 + nu1) * de2 + (fake2 * de2 + nu2) * de1;
    desum = de1 * de2;

    if(abs(nusum) > abs(desum))
    {
        fakesum = nusum / desum;
        nusum = nusum % desum;
    }
    gcdsum = gcd(nusum,desum);
    nusum /= gcdsum;
    desum /= gcdsum;
    if(desum<0)
    {
        nusum *= -1;
        desum *= -1;
    }

    nusub = (fake1 * de1 + nu1) * de2 - (fake2 * de2 + nu2) * de1;
    desub = de1 * de2;
    if(abs(nusub) > abs(desub))
    {
        fakesub = nusub / desub;
        nusub = nusub % desub;
    }
    gcdsub = gcd(nusub,desub);
    nusub /= gcdsub;
    desub /= gcdsub;
    if(desub<0)
    {
        nusub *= -1;
        desub *= -1;
    }

    numul = (fake1 * de1 + nu1) * (fake2 * de2 + nu2);
    demul = de1 * de2;
    if(abs(numul) > abs(demul))
    {
        fakemul = numul / demul;
        numul = numul % demul;
    }
    gcdmul = gcd(numul,demul);
    numul /= gcdmul;
    demul /= gcdmul;
    if(demul<0)
    {
        numul *= -1;
        demul *= -1;
    }
    
    nudiv = (fake1 * de1 + nu1) * de2;
    dediv = (fake2 * de2 + nu2) * de1;
    if(dediv == 0)
    {
        div_0 = true;
    }
    else
    {
        if(abs(nudiv) > abs(dediv))
        {
            fakediv = nudiv / dediv;
            nudiv = nudiv % dediv;
        }
        gcddiv = gcd(nudiv,dediv);
        nudiv /= gcddiv;
        dediv /= gcddiv;
        if(dediv<0)
        {
            nudiv *= -1;
            dediv *= -1;
        }
    }

//    if(fake1>0)
//        cout<<fake1<<" ";
//    if(fake1 < 0)
//        cout<<"("<<fake1<<" ";
//    if(nu1>0||nu1<0&&!fake1)
//        cout<<nu1<<"/"<<de1<<" ";
//    if(nu1<0 && fake1)
//        cout<<nu1*(-1)<<"/"<<de1<<") ";
//    if(!fake1&&!nu1)
//        cout<<"0 ";
//    cout<<"+ ";
//    if(fake2>0)
//        cout<<fake2<<" ";
//    if(fake2<0)
//        cout<<"("<<fake2<<" ";
//    if(nu2>0&&||nu2<0&&!fake2)
//        cout<<nu2<<"/"<<de2<<" ";
//    if(nu2<0&&fake2)
//        cout<<nu2*(-1)<<"/"<<de2<<") ";
//    if(!fake2&&!nu2)
//        cout<<"0 ";
//    cout<<"= ";
//
//    if(fakesum>0)
//        cout<<fakesum<<" ";
//    if(nusum)
//        cout<<nusum<<"/"<<desum<<endl;
//    if(!fakesum&&!nusum)
//        cout<<"0"<<endl;
//
//    if(fake1)
//        cout<<fake1<<" ";
//    if(nu1)
//        cout<<nu1<<"/"<<de1<<" ";
//    if(!fake1&&!nu1)
//        cout<<"0 ";
//    cout<<"- ";
//    if(fake2)
//        cout<<fake2<<" ";
//    if(nu2)
//        cout<<nu2<<"/"<<de2<<" ";
//    if(!fake2&&!nu2)
//        cout<<"0 ";
//    cout<<"= ";
//
//    if(fakesub)
//        cout<<fakesub<<" ";
//    if(nusub)
//        cout<<nusub<<"/"<<desub<<endl;
//    if(!fakesub&&!nusub)
//        cout<<"0"<<endl;
//
//
//
//    if(fake1)
//        cout<<fake1<<" ";
//    if(nu1)
//        cout<<nu1<<"/"<<de1<<" ";
//    if(!fake1&&!nu1)
//        cout<<"0 ";
//    cout<<"* ";
//    if(fake2)
//        cout<<fake2<<" ";
//    if(nu2)
//        cout<<nu2<<"/"<<de2<<" ";
//    if(!fake2&&!nu2)
//        cout<<"0 ";
//    cout<<"= ";
//
//    if(fakemul)
//        cout<<fakemul<<" ";
//    if(numul)
//        cout<<numul<<"/"<<demul<<endl;
//    if(!fakemul&&!numul)
//        cout<<"0"<<endl;
//
//
//    if(fake1)
//        cout<<fake1<<" ";
//    if(nu1)
//        cout<<nu1<<"/"<<de1<<" ";
//    if(!fake1&&!nu1)
//        cout<<"0 ";
//    cout<<"/ ";
//    if(fake2)
//        cout<<fake2<<" ";
//    if(nu2)
//        cout<<nu2<<"/"<<de2<<" ";
//    if(!fake2&&!nu2)
//        cout<<"0 ";
//    cout<<"= ";
//
//    if(div_0)
//        cout<<"Inf"<<endl;
//    else
//    {
//        if(fakediv)
//            cout<<fakediv<<" ";
//        if(nudiv)
//            cout<<nudiv<<"/"<<dediv<<endl;
//        if(!fakediv&&!nudiv)
//            cout<<"0"<<endl;
//    }
//
print(fake1,nu1,de1,fake2,nu2,de2,fakesum,nusum,desum,'+');    
print(fake1,nu1,de1,fake2,nu2,de2,fakesub,nusub,desub,'-');    
print(fake1,nu1,de1,fake2,nu2,de2,fakemul,numul,demul,'*');    
print(fake1,nu1,de1,fake2,nu2,de2,fakediv,nudiv,dediv,'/');    

}
