#include <bits/stdc++.h>

using namespace std;

int main()
{
    //maxheap
    priority_queue<int, vector<int>>p;
    p.push(2);
    p.push(3);
    p.push(1);
    
    cout<<p.top()<<endl;
    while(p.empty()==false){
        cout<<p.top()<<" ";
        p.pop();
    }
    
    //minheap
    priority_queue<int, vector<int>, greater<int>>q;
    q.push(2);
    q.push(1);
    q.push(3);
    
    cout<<q.top()<<endl;
    while(q.empty()==false){
        cout<<q.top()<<" ";
        q.pop();
    }
}