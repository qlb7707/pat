/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/08/05
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "main.h"
#include<iostream>
#include<map>
#include<set>
#include<vector>
#define INF 999999
#define NIL -1
using namespace std;


vector<vector<int> > shortest_path_tree_dijistra(vector<vector<int> > &matrix, int src, int dst)
{
    int n = matrix.size();
    vector<bool> visited(n,false);
    vector<int> shortest = matrix[src];
    set<int> v,left;
    vector<vector<int> > prev(n);
    for(int i = 0; i < n; i++)
    {
        prev[i] = vector<int> (1,src);
    }
    prev[src] = vector<int>(1,NIL);
    for(int i = 0; i < n; i++)
    {
        if(i == src)
            continue;
        left.insert(i);
    }
    v.insert(src);
    visited[src] = true;
    while(!left.empty())
    {
        int min = INF,min_idx = NIL;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && shortest[i] < min)
            {
                min = shortest[i];
                min_idx = i;
            }
        }
        v.insert(min_idx);
        auto it = left.find(min_idx);
        left.erase(it);
        if(min_idx == dst)
            break;
        //do relaxation
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && (shortest[min_idx] + matrix[min_idx][i] < shortest[i]))
            {
                shortest[i] = shortest[min_idx] + matrix[min_idx][i];
                prev[i] = vector<int> (1,min_idx);

            }
            else if(!visited[i] && (shortest[min_idx] + matrix[min_idx][i] == shortest[i]))
            {
                prev[i].push_back(min_idx);
            }
        }
        visited[min_idx] = true;

    }
    matrix[src] = shortest;
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

int compute_happy_and_avg(vector<int> path,vector<int> h_city,int &avg)
{
    if(path.empty() || path.size() == 1)
    {
        return -1;
    }
    int n = path.size();
    int sum = 0;
    for(int i = 0; i < n - 1; i++)
    {
        sum += h_city[path[i] - 1];
    }
    avg = sum/(n - 1);
    return sum;

}

int find_best_path(vector<vector<int> >path,vector<int> h_city,vector<int> &path_happy,vector<int> &avg)
{
    int n = path.size();
    int max = -1,avg_max = -1,max_idx = -1;
    int avg_happy = 0;
    for(int i = 0; i < n; i++)
    {
        int h = compute_happy_and_avg(path[i],h_city,avg_happy);
        path_happy.push_back(h);
        avg.push_back(avg_happy);
        if(h > max)
        {
            max = h;
            max_idx = i;
            avg_max = avg_happy;
        }
        else if(h == max)
        {
            if(avg_max < avg_happy)
            {
                max_idx = i;
                avg_max = avg_happy;
            }
        }
    }
    return max_idx;
}

int main()
{
    int n_cities,n_road,happy;
    string start,name;
    cin >> n_cities >> n_road >> start;
    map<string,int> mp_idx;
    map<int,string> mp_rev;
    vector<int> city_happy,path_happy,avg;
    vector<vector<int> > path_tree,all;
    vector<vector<int> > matrix(n_cities,vector<int> (n_cities,INF));
    mp_idx[start] = 0;
    mp_rev[0] = start;
    for(int i = 1; i < n_cities; i++)
    {
        cin >> name >> happy;
        mp_idx[name] = i;
        mp_rev[i] = name;
        city_happy.push_back(happy);
    }
    for(int i = 0; i < n_road; i++)
    {
        string ct1,ct2;
        int cost;
        cin >> ct1 >> ct2 >> cost;
        matrix[mp_idx[ct1]][mp_idx[ct2]] = cost;
        matrix[mp_idx[ct2]][mp_idx[ct1]] = cost;
    }
    path_tree = shortest_path_tree_dijistra(matrix,mp_idx[start],mp_idx["ROM"]);
    all_path(mp_idx["ROM"],path_tree,vector<vector<int> >(),all);
    int best = find_best_path(all,city_happy,path_happy,avg);
    cout<<all.size()<<" "<<matrix[mp_idx[start]][mp_idx["ROM"]]<<" "<<path_happy[best]<<" "<<avg[best]<<endl;
    for(int i = all[best].size()-1; i >= 0; i--)
    {
        if(i > 0)
            cout<<mp_rev[all[best][i]]<<"->";
        else
            cout<<mp_rev[all[best][i]]<<endl;
    }
    

}
