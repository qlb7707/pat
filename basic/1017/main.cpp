#include<iostream>
#include<cmath>
using namespace std;
 
int main()
{
    int n;
    char c;
    cin>>n>>c;
    int sum = 1;
    int i = 1;
    int left;
    while(sum + (2*i + 1)*2 <= n)
    {
        sum += (2*i + 1)*2;
        i++;
    }
    i--;
    left = n - sum;
    for(int m = -i;m <= i; m++)
    {
        int nsig = 2*i + 1 - 2*(i-abs(m));
        int nspace = i - abs(m);
        for(int j = 0;j<nspace;j++)
        {
            cout<<" ";   
        }
        for(int j = 0;j< nsig; j++)
        {
            cout<<c;   
        }
        for(int j = 0;j<nspace;j++)
        {
            cout<<" ";   
        }
        cout<<endl;
    }
    cout<<left<<endl;
    return 0;
}
