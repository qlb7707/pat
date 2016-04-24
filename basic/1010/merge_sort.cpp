/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :quick_sort.cpp
*   author       :qinlibin
*   create date  :2016/04/08
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<vector>
using namespace std;


void part(vector<int> &v1,vector<int> &v2,vector<int> &src)
{
    if(src.empty())
        return;
    int n = src.size();
    int n1 = n/2;
    int n2 = n - n1;
    for(int i = 0;i < n1;i++)
    {
        v1.push_back(src[i]);
    }
    for(int i = n1;i < n;i++)
    {
        v2.push_back(src[i]);
    }
}

vector<int> merge(vector<int> v1,vector<int> v2)
{
    vector<int> ans;
    int n1 = v1.size();
    int n2 = v2.size();
    int cnt1 = 0,cnt2 = 0;
    while(cnt1 < n1 && cnt2 < n2)
    {
        if(v1[cnt1] > v2[cnt2])
        {
            ans.push_back(v1[cnt1]);
            cnt1++;
        }
        else
        {
            ans.push_back(v2[cnt2]);
            cnt2++;
        }
    }
    if(cnt1 < n1)
    {
        for(int i = cnt1;i < n1;i++)
        {
            ans.push_back(v1[i]);
        }
    }
    if(cnt2 < n2)
    {
        for(int i = cnt2;i < n2; i++)
        {
            ans.push_back(v2[i]);
        }
    }

    return ans;

}

vector<int> merge_sort(vector<int> src)
{
    vector<int> v1,v2,sv1,sv2,ans;
    if(src.empty())
        return ans;
    int n = src.size();
    if(n == 1)
        return src;
    part(v1,v2,src);
//    cout<<v1.size()<<" "<<v2.size()<<endl;
    sv1 = merge_sort(v1);
    sv2 = merge_sort(v2);
    ans = merge(sv1,sv2);
    return ans;
}

int main()
{

    int n;
    int nout;
    vector<int> input;
    vector<int> out;
    cin>>n;
    int num;
    for(int i = 0; i < n;i++)
    {
        cin>>num;
        input.push_back(num);
    }
    out = merge_sort(input);
    nout = out.size();
    for(int i = 0;i < nout;i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;

}
