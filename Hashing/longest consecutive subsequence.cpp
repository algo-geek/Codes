// naive
#include <bits/stdc++.h>
using namespace std;

int findLongest(int arr[], int n)
{
    sort(arr,arr+n);
    int res=1,curr=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]+1)
            curr++;
        else{
            res=max(res,curr);
            curr=1;
        }
    }
    res=max(res,curr);
    return res;
}

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << findLongest(arr, n);
}

//efficient
#include <bits/stdc++.h>
using namespace std;

int findLongest(int arr[], int n)
{
    unordered_set<int> s;
    int res = 0;
 
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
 
    for (int i = 0; i < n; i++) {
        if (s.find(arr[i] - 1) == s.end()) {
            int curr = 1;
            while (s.find(curr+arr[i]) != s.end())
                curr++;
                
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << findLongest(arr, n);
}