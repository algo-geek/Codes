#include <bits/stdc++.h>
using namespace std;

void moveZeros(int a[], int n)
{
    // to keep count of non-zero elements
    int c=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i], a[c]);
            c++;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    moveZeros(a, n);

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}