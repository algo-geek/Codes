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
    
    sort(a, a+n);
    
    for(int i=0;i<n;i++)
    {
        int l=i+1, r=n-1;
        
        while(l<r)
        {
            int cur=a[i]+a[l]+a[r];
            
            if(cur==k)
            {
                ans=true;
                break;
            }
            else if(cur<k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
       
    }
    
     cout<<ans<<endl;
}