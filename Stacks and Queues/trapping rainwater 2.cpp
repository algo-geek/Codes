#include<bits/stdc++.h>
using namespace std;

int rainwater(vector<int>a)
{
    stack<int>s;
    int n=a.size(), ans=0;
    
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()]<a[i])
        {
            int cur=s.top();
            s.pop();
            
            if(s.empty())// if there's no greater bar than cur bar on its left to hold the container
            {
                break;
            }
            
            int dif=i-s.top()-1; // width 
            ans+=(min(a[s.top()], a[i]) - a[cur]) * dif;
        }
        s.push(i);//index 
    }
    return ans;
    
}

int main()
{
    vector<int>a={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    cout<<rainwater(a);
}