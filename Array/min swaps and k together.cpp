// min swaps to bring elements less than or equal to k together
// sliding window
#include <bits/stdc++.h>
using namespace std;

int minSwap(int a[], int n, int k) 
{
        int c=0, x=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=k)
            c++;
        }
        if(c==0 || c==1 || c==n)
        return 0;
        
        for(int i=0;i<c;i++)
        {
            if(a[i]>k)
            x++;
        }
        int m=x;
        for(int i=c;i<n;i++)
        {
            if(a[i-c]>k)
            x--;
            
            if(a[i]>k)
            x++;
            
            m=min(m, x);
        }
        return m;
}

int main() 
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";
     
    int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    n = sizeof(arr1) / sizeof(arr1[0]);
    k = 5;
    cout << minSwap(arr1, n, k);
    return 0;
}