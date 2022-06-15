#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int prevfact=factorial(n-1);
    return n*prevfact;
}

//making it tail recursive
int factorial(int n, int k)
{
    if(n==0 || n==1)
    {
        return k;
    }
    return factorial(n-1, k*n);
}

int main()
{
    int n;
    cin>>n;
    
    cout<<factorial(n)<<endl;
}