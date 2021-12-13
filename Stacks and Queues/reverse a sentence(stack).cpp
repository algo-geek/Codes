#include <iostream>
#include <stack>
using namespace std;

void reverse(string r)
{
    stack<string>s;
    
    for(int i=0;i<r.size();i++)
    {
        string w="";
        
        while(r[i]!=' ' && i<r.size())
        {
            w+=r[i];
            i++;
        }
        
        s.push(w);
    }
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    string r="Hey, how are you doing?";
    
    reverse(r);
    
}