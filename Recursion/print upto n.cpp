#include <iostream>
using namespace std;

void decrease(int n)
{
    if(n==0)//if(n==1) { cout<<"1"<<endl;};
    return;//return;
    
    cout<<n<<endl;
    decrease(n-1);
}

void increase(int n)
{
    if(n==0)
    return;
    
    increase(n-1);
    cout<<n<<endl;
}

int main()
{
    int n;
    cin>>n;
    
    decrease(n);
    increase(n);
}