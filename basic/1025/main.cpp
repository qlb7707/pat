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
#include<vector>
using namespace std;

bool is_insert(vector<int> ori,vector<int> med,int &p)
{
    int n = med.size();
    int i;
    for(i = 0; i < n-1; i++)
    {
        if(med[i]>med[i+1])
        {
            break;
        }
    }
    for(int j = i+1; j < n; j++)
    {
        if(med[j] != ori[j])
            return false;
    }
    p = i;
    return true;

}

vector<int> next_insert(vector<int> med, int p)
{
    vector<int> ans = med;
    int num = med[p+1];
    int i;
    ans.erase(ans.begin()+p+1);
    for(i = 0;i <= p;i++)
    {
        if(ans[i]>num)
        {
            break;
        }
    }
    ans.insert(ans.begin()+i,num);
    return ans;

}

vector<int> next_merge(vector<int> med)
{
    int sub_size = 2;
    bool found_p = false;
    int p = 0;
    int cur_p = 0;
    vector<int> ans;
    while(!found_p)
    {
        for(int i = 0;i < sub_size - 1;i++)
        {
            if(med[p+i] > med[p+i+1])
            {
                found_p = true;
                break;
            }
            if(p+i+1 == med.size() - 1)
            {
                break;
            }
        }
        if(found_p)
            break;
        if(p+sub_size >= med.size())
        {
            p = 0;
            sub_size *= 2;
        }
        else
        {
            p += sub_size;
        }
    }
    cur_p = sub_size/2;
//    cout<<"cur_p = "<<cur_p<<endl;
    int p1 = 0,p2 = p1 + cur_p;

    while(p1 <= med.size()-1 && p2 <= med.size() - 1)
    {
        int cnt1 = 0,cnt2 = 0;
        while((cnt1 < cur_p || cnt2 < cur_p) && p2 + cnt2 < med.size())
        {
            if(cnt1 == cur_p)
            {
                while(cnt2<cur_p)
                {
                    ans.push_back(med[p2 + cnt2]);
                    cnt2 ++;
                    if(cnt2 + p2 >= med.size())
                        break;
                }

            }
            else if(cnt2 == cur_p)
            {
                while(cnt1<cur_p)
                {
                    ans.push_back(med[p1+cnt1]);
                    cnt1 ++;
                }
            }
            else
            {
                while(cnt1<cur_p&&cnt2<cur_p)
                {
                    if(med[cnt1+p1] >= med[cnt2+p2])
                    {
                        ans.push_back(med[cnt2+p2]);
                        cnt2++;
                        if(cnt2 + p2 >= med.size())
                            break;

                    }
                    else
                    {
                        ans.push_back(med[cnt1+p1]);
                        cnt1++;
                    }
                }
                while(cnt1<cur_p)
                {
                    ans.push_back(med[cnt1+p1]);
                    cnt1++;
                }
            }
        }
        p1 += 2*cur_p;
        p2 += 2*cur_p;

    }

    if(p1<med.size())
    {
        for(int i = p1; i < med.size(); i++)
        {
            ans.push_back(med[i]);
        }
    }

    return ans;

}


int main()
{
    int N;
    vector<int> ori,med,next;
    int num,pos;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        ori.push_back(num);
    }
    for(int i=0;i<N;i++)
    {
        cin>>num;
        med.push_back(num);
    }

    if(is_insert(ori,med,pos))
    {
        cout<<"Insertion Sort"<<endl;
        next = next_insert(med,pos);
    }
    else
    {
        cout<<"Merge Sort"<<endl;
        next = next_merge(med);
    }

    for(int i = 0;i < next.size();i++)
    {
        if(i == next.size()-1)
        {
            cout<<next[i]<<endl;
        }
        else
        {
            cout<<next[i]<<" ";
        }
    }
    return 0;
    
}
