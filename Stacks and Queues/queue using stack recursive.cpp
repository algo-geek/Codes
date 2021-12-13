#include <bits/stdc++.h>
using namespace std;

class que{
    stack<int>s1;
    
    public:
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(s1.empty())
        {
            cout<<"error"<<endl;
            return -1;
        }
        
        int x=s1.top();
        s1.pop();
        
        if(s1.empty())//if only 1 element
        {
            return x;
        }
        
        int item=pop();//recursively pop all items until there is only 1 element left
        s1.push(x);// after we get result push all items popped earlier
        return item;
        
    }
    
     bool empty()
    {
        return (s1.empty());
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