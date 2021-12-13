#include <bits/stdc++.h>
using namespace std;

class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){   //stack constructor
        n=0;
    }
    
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    void pop(){
        q1.pop();
        n--;
    }
    
    int top(){
        return q1.front();
    }
    
    int size(){
        return n;
    }
    
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
}