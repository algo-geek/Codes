// dp1
#include <iostream>
#include <limits.h>
using namespace std;

int maxSum(int arr[], int n)
{
	if(n==0)
		return arr[0];

	int dp[n+1];

	dp[1] = arr[0];
	dp[2] = max(arr[0], arr[1]);

	for(int i=3; i<=n; i++)
	{
		dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
	}

	return dp[n];
}


int main() {
    
    	int n = 5, arr[]= {10, 20, 30, 40, 50};
    	
    	cout<<maxSum(arr, n);
    	
    	return 0;
}

// dp2
#include <iostream>
#include <limits.h>
using namespace std;

int maxSum(int arr[], int n)
{
	if(n==0)
		return arr[0];

		int prev_prev = arr[0];
		int prev = max(arr[0], arr[1]);
		int res = prev;

		for(int i=3; i<=n; i++)
		{
			res = max(prev, prev_prev + arr[i-1]);

			prev_prev = prev;

			prev = res;
		}

		return res;
}


int main() {
    
    	int n = 5, arr[]= {10, 20, 30, 40, 50};
    	
    	cout<<maxSum(arr, n);
    	
    	return 0;
}