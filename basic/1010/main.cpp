#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
bool compare(pair<int,double> p1,pair<int,double> p2)
{
    if(p1.second < p2.second)
        return false;
    else
        return true;
}
 
void part(vector<pair<int,double> > &v1,vector<pair<int,double> > &v2,vector<pair<int,double> > &src)
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

vector<pair<int,double> > merge(vector<pair<int,double> > v1,vector<pair<int,double> > v2)
{
    vector<pair<int,double> > ans;
    int n1 = v1.size();
    int n2 = v2.size();
    int cnt1 = 0,cnt2 = 0;
    while(cnt1 < n1 && cnt2 < n2)
    {
        if(v1[cnt1].second > v2[cnt2].second)
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

vector<pair<int,double> > merge_sort(vector<pair<int,double> > src)
{
    vector<pair<int,double> > v1,v2,sv1,sv2,ans;
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
   int N,D;
   cin>>N>>D;
   vector<int> stores,prices;
   vector<pair<int,double> > pprices;
   int s,p;
   double sum = 0;
   for(int i = 0; i < N; i++)
   {
       cin>>s;
       stores.push_back(s);
   }
   for(int i = 0; i < N; i++)
   {
       cin>>p;
       prices.push_back(p);
       pprices.push_back(pair<int,double>(i,1.0*p/stores[i]));
   }
   // sort(pprices.begin(),pprices.end(),compare);
    pprices = merge_sort(pprices);
    for(int i = 0; i < N;i++)
    {
        if(stores[pprices[i].first] <= D)
        {
            sum += prices[pprices[i].first];
            D -= stores[pprices[i].first];
        }
        else
        {
            sum += D * pprices[i].second;
            D = 0;
            break;
        }
    }      
   cout<<fixed<<setprecision(2)<<sum<<endl;
    
   return 0;
}
