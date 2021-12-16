#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int i=0;i<n;i++)
    {
        int d=0;
        
        for(int j=i;j>=0;j--)
        {
            if(a[i]>=a[j])
            d++;
            else
            break;
        }
        cout<<d<<endl;
    }
}

//7
// 100 80 60 70 60 75 85