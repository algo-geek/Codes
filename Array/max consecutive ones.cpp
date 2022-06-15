// naive
#include <iostream>
#include <cmath>
using namespace std;


int maxConsecutiveOnes(int arr[], int n)
{
	int res = 0;

	for(int i = 0; i < n; i++)
	{
		int curr = 0;

		for(int j = i; j < n; j++)
		{
			if(arr[j] == 1) curr++;
			else break;
		}

		res = max(res, curr);
	}
	
	return res;
}



int main() {
	
     int arr[] = {0, 1, 1, 1, 0, 1, 1}, n = 7;

     cout<<maxConsecutiveOnes(arr, n);
    
}

// efficient
#include <iostream>
#include <cmath>
using namespace std;


int maxConsecutiveOnes(int arr[], int n)
{
	int res = 0, curr = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] == 0)
			curr = 0;
		else
		{
			curr++;

			res = max(res, curr);
		}
	}
	
	return res;
}



int main() {
	
     int arr[] = {0, 1, 1, 0, 1, 1, 1}, n = 7;

     cout<<maxConsecutiveOnes(arr, n);
    
}

// sliding window
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    
    vector<int>a(n);
    
    for(auto &i:a)
    cin>>i;
    
    // a[i...j] ----> window
    // a[i....j+1]  -----> window size increase
    // a[i+1....j]  -----> window size decrease
    
    int i=0, c=0, r=0;
    
    for(int j=0;j<n;j++)
    {
        if(a[j]==0)//5
        c++;//3
        
        while(c>k)
        {
            if(a[i]==0)
            {
                c--;//2
            }
            
            i++;//4
        }
        
        // c <= k
        
        r=max(r, j-i+1);
        cout<<j<<" "<<i<<" "<<r<<endl;
    }
    
    cout<<r<<endl;
}