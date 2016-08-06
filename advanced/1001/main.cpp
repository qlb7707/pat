/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/08/02
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "main.h"
//
#include<iostream>
#include<vector>
#include<set>
//#include<deque>
#include<algorithm>
#define INF 999999
#define NIL -1
using namespace std;

vector<vector<int> > shortest_path(int n_node,int src,int dst, vector<vector<int> > M)
{
    set<int> v;
    set<int> left;
    vector<int> shortest = M[src];
    vector<vector<int> > prev(n_node+1);

    for(int i = 0; i <= n_node; i++)
    {
        if(0 == i)
            prev[i].push_back(NIL);
        else
            prev[i].push_back(0);
            
    }
    for(int i = 1; i <= n_node; i++)
    {
       left.insert(i); 
    }
    v.insert(0);

    while(!left.empty())
    {
        int min = INF,min_idx = -1;
        for(int i = 1; i <= n_node; i++)
        {
            if(left.find(i)==left.end())
                continue;
            if(shortest[i] < min)
            {
                min = shortest[i];
                min_idx = i;
            }
        }
        set<int>::iterator it = left.find(min_idx);
        left.erase(it);
        v.insert(min_idx);
        if(min_idx == dst)
            break;
        //relaxation
        for(int i = 0; i <= n_node; i++)
        {
            if((shortest[min_idx] + M[min_idx][i] < shortest[i])&&v.find(i)==v.end())
            {
                shortest[i] = shortest[min_idx] + M[min_idx][i];
                prev[i] = vector<int>(1,min_idx);
            }
            else if((shortest[min_idx] + M[min_idx][i] == shortest[i])&&v.find(i)==v.end())
            {
                prev[i].push_back(min_idx);
            }
        }

    }

    return prev;

}

void all_path(int dst,vector<vector<int> > tree,vector<vector<int> > cur,vector<vector<int> >& ans)
{
    if(dst == NIL)
        return;
    if(cur.empty())
    {
        vector<int> tmp;
        tmp.push_back(dst);
        cur.push_back(tmp);
    }
    else
    {
        int n = cur.size();
        for(int i = 0; i < n; i++)
        {
            cur[i].push_back(dst);
        }
    }
    int m = tree[dst].size();
    for(int i = 0; i < m; i++)
    {
        if(tree[dst][i] == NIL)
        {
//          cout<<"find path"<<endl;
            for(int j = 0; j < cur.size(); j++)
            {
                ans.push_back(cur[j]);
            }
        }
        all_path(tree[dst][i],tree,cur,ans);
    }


}

void print_tree(int s,vector<vector<int> >paths)
{
    vector<int> cur = paths[s];
    int n = cur.size();
    if(n == 0 || cur[0] == NIL)
    {
        return;
    }
    for(int i = 0; i < n; i++)
    {
        cout<<cur[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        print_tree(cur[i],paths);
    }
}


int need_bikes(vector<int> bikes,vector<int> path,int perf,int& over)
{
    if(path.empty()||path.size() == 1)
    {
        return INF;
    }
    path.pop_back();
    int sum = 0;
    over = 0;
    while(!path.empty())
    {
        int idx = path.back();
        path.pop_back();
        if(bikes[idx-1] >= perf)
        {
            over += (bikes[idx-1] - perf);
        }
        else
        {
            if(over >= perf - bikes[idx-1])
            {
                over -= (perf - bikes[idx-1]);
            }
            else
            {
//                over = 0;
                sum += perf - bikes[idx-1] -over;
                over = 0;
            }

        }
    }
    return sum;
}


int find_best_path(vector<vector<int> > path,vector<int> bikes,int perf,vector<int> &send,vector<int> &take)
{
    int n = path.size();
    int min = INF,min_idx = -1;
    int over = 0;
    for(int i = 0; i < n; i++)
    {
        int need = need_bikes(bikes,path[i],perf,over);
        take.push_back(over);
        send.push_back(need);
        if(need < min)
        {
            min = need;
            min_idx = i;
        }
    }
    return min_idx;
}




int main()
{
    int c_max,n_station,sp,n_roads;
    cin >> c_max >> n_station >> sp >> n_roads;
    vector<int> contain_bikes(n_station,0);
    vector<vector<int> > paths;
    vector<vector<int> > all,cur;
    vector<int> results,take;
    vector<vector<int> > matrix(n_station+1,vector<int> (n_station+1,INF));
    for(int i = 0 ;i < n_station;i++)
    {
        cin >> contain_bikes[i];
    }

    for(int i = 0; i < n_roads; i++)
    {
        int s,d,v;
        cin>>s>>d>>v;
        matrix[s][d] = v;
        matrix[d][s] = v;
    }
                
    paths = shortest_path(n_station,0,sp,matrix);
    all_path(sp,paths,cur,all);
    int min_idx = find_best_path(all,contain_bikes,c_max/2,results,take);

    cout<<results[min_idx]<<" ";
    while(!all[min_idx].empty())
    {
        if(all[min_idx].size() != 1)
        {
            cout<<all[min_idx].back()<<"->";
        }
        else
        {
            cout<<all[min_idx].back()<<" ";
        }
        all[min_idx].pop_back();
    }

    cout<<take[min_idx]<<endl;

    
//    cout<<all.size()<<endl;
    
//    cout<<"0"<<endl;
//    print_tree(sp,paths);
//    cout<<sp<<endl;

}

