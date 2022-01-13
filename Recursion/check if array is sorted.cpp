#include <iostream>
using namespace std;

bool sorted(int a[], int n)
{
    if(n==1)
    return true;
    
    bool restarray=sorted(a+1, n-1);
    return (a[0]<a[1] && restarray);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    cout<<sorted(a, n)<<endl;
}