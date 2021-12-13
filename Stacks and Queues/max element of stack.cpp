#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, x, y;
    cin>>n;
    
    stack<int>s;
    
    while(n--)
    {
        cin>>x;
        
        if(x==1)
        {
            cin>>y;
            
            if(s.empty())
            s.push(y);
            else
            s.push(max(y, s.top()));
        }
        else if(x==2)
        {
            s.pop();
        }
        else
        {
            cout<<s.top()<<endl;
        }
    }
}