#include<bits/stdc++.h>
using namespace std;

void swap(int a[], int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void dnfsort(int a[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a, low, mid);
            low++;
            mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a, high, mid);
            high--;
        }
    }
}

int main()
{
    int a[]={1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    dnfsort(a, 10);
    
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
}