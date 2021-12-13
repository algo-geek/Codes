#include <bits/stdc++.h>
using namespace std;

void swap(int a[], int i, int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int partition(int a[], int l, int r)
{
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<pivot)
        {
           i++;
           swap(a,i,j);
        }
    }
    swap(a, i+1, r);
    return i+1;
}

void quicksort(int a[], int l, int r)
{
    if(l<r)
    {
        int pi=partition(a, l, r);
        quicksort(a, l, pi-1);
        quicksort(a, pi+1, r);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    quicksort(a, 0, n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}