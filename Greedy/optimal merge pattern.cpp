// connect n ropes with min cost
// O(n log n) time and O(n) space

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int>a(n);
        
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    priority_queue<int, vector<int>,greater<int>>p;
    
    for(int i=0;i<n;i++)
    p.push(a[i]);
    
    int r=0;
    
    while(p.size()>1)
    {
         int e1 = p.top();
        p.pop();
        int e2 = p.top();
        p.pop();
 
        r += e1 + e2;
        p.push(e1 + e2);
    }
    
    cout << r << endl;
}