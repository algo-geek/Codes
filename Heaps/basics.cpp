#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    priority_queue<int, vector<int>>p;
    p.push(2);
    p.push(3);
    p.push(1);
    
    p.pop();
    
    cout<<p.top()<<endl;
    
    priority_queue<int, vector<int>, greater<int>>q;
    q.push(2);
    q.push(1);
    q.push(3);
    
    cout<<q.top()<<endl;
}