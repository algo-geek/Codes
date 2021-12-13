#include <bits/stdc++.h>
using namespace std;

class que{
    stack<int>s1;
    stack<int>s2;
    
    public:
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(s1.empty() && s2.empty())
        {
            cout<<"error"<<endl;
            return -1;
        }
        
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
           
        }
        
         int topval=s2.top();
            s2.pop();
            return topval;
    }
    
     bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

int main()
{
    que s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.pop()<<endl;
    
    s.push(5);
    
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
}