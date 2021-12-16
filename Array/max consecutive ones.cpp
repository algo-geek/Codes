#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int>a(n);
    
    for(auto &i:a)
    cin>>i;
    
    // a[i...j] ----> window
    // a[i....j+1]  -----> window size increase
    // a[i+1....j]  -----> window size decrease
    
    int i=0, c=0, r=0;
    
    for(int j=0;j<n;j++)
    {
        if(a[j]==0)//5
        c++;//3
        
        while(c>k)
        {
            if(a[i]==0)
            {
                c--;//2
            }
            
            i++;//4
        }
        
        // c <= k
        
        r=max(r, j-i+1);
        cout<<j<<" "<<i<<" "<<r<<endl;
    }
    
    cout<<r<<endl;
}