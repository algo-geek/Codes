#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>p1, pair<int, int>p2)
{
    double x1=(double) p1.first/p1.second;
    double x2=(double) p2.first/p2.second;
    
    return x1>x2;
}

int main()
{
    int n, w;
    cin>>n>>w;
    
    vector<pair<int, int>>a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    
    sort(a.begin(), a.end(), compare);
    
    int r=0;
    
    for(int i=0;i<n;i++)
    {
        if(w>=a[i].second)
        {
            r+=a[i].first;
            w-=a[i].second;
            continue;
            
        }
        
        double vw=(double) a[i].first/a[i].second;
        r+= vw*w;
        w=0;
        break;
        
    }
    
    cout<<r<<endl;
    
}