#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
        unordered_map<int, int> ump;
        int sum = 0, maxLen = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum == K)
            maxLen = i+1;
         
            if(ump.find(sum-K) != ump.end())
            {
                if(maxLen < i - ump[sum-K])
                maxLen = i - ump[sum-K];
             
            }
            // if prefix sum already exists in map, don't update it as it will only shorten the length of subarray
            if(ump.find(sum)==ump.end())
            {
                ump[sum] = i;
            }
        }
    
        return maxLen;
    } 

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

    cout<<lenOfLongSubarr(a, n, k)<<endl;
}