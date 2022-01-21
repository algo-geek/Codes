#include <bits/stdc++.h>
using namespace std;

long long merge(int a[], int l, int mid, int r)
{
    long long cnt=0;
    int n1=mid-l+1;
    int n2=r-mid;
    
    int b[n1];// temp arrays
    int c[n2];
    
    for(int i=0;i<n1;i++)
    b[i]=a[l+i];
    
    for(int i=0;i<n2;i++)
    c[i]=a[mid+1+i];
    
    int i=0;//for n1 array
    int j=0;//for n2 array
    int k=l;// for final array
    
    while(i<n1 && j<n2)
    {
        if(b[i]<c[j])
        {
            a[k]=b[i];
            k++;
            i++;
        }
        else
        {
            a[k]=c[j];
            cnt+=n1-i;
            k++;
            j++;
        }
    }
    
    while(i<n1){
        a[k]=b[i];
            k++;
            i++;
    }
    while(j<n2)
    {
        a[k]=c[j];
            k++;
            j++;
    }
    return cnt;
}

long long mergesort(int a[], int l, int r)
{
    long long cnt=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        cnt+=mergesort(a, l, mid);
        cnt+=mergesort(a, mid+1, r);
        
        cnt+=merge(a, l, mid, r);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<mergesort(a, 0, n-1);

}