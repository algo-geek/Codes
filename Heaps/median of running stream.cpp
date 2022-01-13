
#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>>p;//maxheap
priority_queue<int, vector<int>, greater<int>>q;//minheap

void insert(int x)
{
    if(p.size()==q.size())
    {
        if(p.size()==0)
        {
            p.push(x);
            return;
        }
        if(x<p.top())
        {
            p.push(x);
        }
        else
        {
            q.push(x);
        }
    }
    else
    {
        if(p.size()>q.size())
        {
            if(x>=p.top())
            {
                q.push(x);
            }
            else
            {
                int temp=p.top();
                p.pop();
                q.push(temp);
                p.push(x);
            }
        }
        else
        {
            if(x<=q.top())
            {
                p.push(x);
            }
            else
            {
                int temp=q.top();
                q.pop();
                p.push(temp);
                q.push(x);
            }
        }
    }
}

double findmedian()
{
    if(p.size()==q.size())
    {
        return (p.top()+q.top())/2.0;
    }
    else if(p.size()>q.size())
    {
        return p.top();
    }
    else
    {
        return q.top();
    }
}

int main()
{
    
    
    insert(10);
    cout<<findmedian()<<endl;
    insert(15);
    cout<<findmedian()<<endl;
    insert(21);
    cout<<findmedian()<<endl;
    insert(30);
    cout<<findmedian()<<endl;
    insert(18);
    cout<<findmedian()<<endl;
    insert(19);
    cout<<findmedian()<<endl;
    
}

