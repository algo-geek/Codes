#include<bits/stdc++.h>
using namespace std;

vector<int>stock(vector<int>a)
{
    vector<int>ans;
    
    stack<pair<int, int>>s;
    
    for(auto i:a)
    {
        int d=1;
        while(!s.empty() && s.top().first<=i)
        {
            d+=s.top().second;// adding days
            s.pop();
        }
        s.push({i, d});
        ans.push_back(d);
    }
    
    return ans;
}

int main()
{
    
    vector<int>a={100, 80, 60, 70, 60, 75, 85};
    vector<int>r=stock(a);
    
    for(auto i:r)
    cout<<i<<" ";
}