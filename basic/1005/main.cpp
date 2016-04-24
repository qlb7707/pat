/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/03/27
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu{
    int d;
    int c;
    string num;
    stu(string no,int a,int b){
        num = no;
        d = a;
        c = b;
    }
};

bool compare(stu s1,stu s2)
{
    if(s1.c + s1.d < s2.c + s2.d)
        return false;
    else if(s1.c + s1.d == s2.c + s2.d && s1.d < s2.d)
        return false;
    else if(s1.c + s1.d == s2.c + s2.d && s1.d == s2.d && s2.num < s1.num) 
        return false;
    else
        return true;
}

int main()
{
    int N,L,H;
    cin>>N>>L>>H;
    int d,c;
    string num;
    vector<stu> studentsA;
    vector<stu> studentsB;
    vector<stu> studentsC;
    vector<stu> studentsD;
    for(int i = 0;i < N; i++)
    {
        cin>>num>>d>>c;
        if(!(d>=L&&c>=L))
            continue;
        if(d>=H&&c>=H)
            studentsA.push_back(stu(num,d,c));
        else if(d>=H && c<H)
            studentsB.push_back(stu(num,d,c));
        else if(d<H && c<H && d>=c)
            studentsC.push_back(stu(num,d,c));
        else
            studentsD.push_back(stu(num,d,c));
    }
    sort(studentsA.begin(),studentsA.end(),compare);
    sort(studentsB.begin(),studentsB.end(),compare);
    sort(studentsC.begin(),studentsC.end(),compare);
    sort(studentsD.begin(),studentsD.end(),compare);
    cout<<studentsA.size()+studentsB.size()+studentsC.size()+studentsD.size()<<endl;
    for(int i = 0; i < studentsA.size(); i++)
    {
        cout<<studentsA[i].num<<" "<<studentsA[i].d<<" "<<studentsA[i].c<<endl;
    }
    for(int i = 0; i < studentsB.size();i++)
    {
        cout<<studentsB[i].num<<" "<<studentsB[i].d<<" "<<studentsB[i].c<<endl;
    }
    for(int i = 0; i < studentsC.size();i++)
    {
        cout<<studentsC[i].num<<" "<<studentsC[i].d<<" "<<studentsC[i].c<<endl;
    }
    for(int i = 0; i < studentsD.size();i++)
    {
        cout<<studentsD[i].num<<" "<<studentsD[i].d<<" "<<studentsD[i].c<<endl;
    
    }
    return 0;

}
