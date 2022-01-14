#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>>v;
    
    int s, e;
        
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)// sort by end time
    {
        return a[1]<b[1];
    });
    
    int r=1;
    int end=v[0][1];// end of 1st activity
    
    for(int i=1;i<n;i++)
    {
        if(v[i][0]>=end)
        {
            r++;
            end=v[i][1];
        }
    }
    
    cout<<r<<endl;
}