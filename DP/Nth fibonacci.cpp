// memoization
#include<bits/stdc++.h>
using namespace std;

int m[1000000];

int fibo(int n)
{
    // int ans;
    if(m[n]==-1)
    {
        if(n==0 || n==1)
        return n;
        else
        m[n]= fibo(n-1)+fibo(n-2);

        // m[n]=ans;
    }
    return m[n];
}

int main()
{
    int n;
    cin>>n;

    memset(m, -1, sizeof(m));

    cout<<fibo(n)<<endl;
}

//tabulation

#include<bits/stdc++.h>
using namespace std;


int fibo(int n)
{
    int m[n+1];
    m[0]=0;
    m[1]=1;

    for(int i=2;i<=n;i++)
    {
        m[i]=m[i-1]+m[i-2];
    }

    return m[n];
}

int main()
{
    int n;
    cin>>n;


    cout<<fibo(n)<<endl;
}