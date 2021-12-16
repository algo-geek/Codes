#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n, k;
    cin>>n>>k;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    bool ans=false;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int x=j+1;x<n;x++)
            {
                if(a[i]+a[j]+a[x]==k)
                {
                    ans=true;
                    break;
                }
            }
        }
       
    }
    
     cout<<ans<<endl;
}