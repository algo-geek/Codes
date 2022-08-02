// recursion // O(n^2)
#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{

	if (n == 1)
		return 0;

	int res = INT_MAX;
	for (int i = n - 2; i >= 0; i--) 
    {
		if (i + arr[i] >= n - 1) 
        {
			int sub_res = minJumps(arr, i + 1);

            // if result exists
			if (sub_res != INT_MAX)
				res = min(res, sub_res + 1);
		}
	}

	return res;
}

int main()
{
	int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of jumps"<< minJumps(arr, n);
	return 0;
}



// dp // O(n^2)
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

      
  int minJumps(int arr[], int n) 
    { 
        
        int dp[n]; 
        int i, j; 
      
       
        dp[0] = 0; 
      
        
        for (i = 1; i < n; i++) { 
            dp[i] = INT_MAX; 
            for (j = 0; j < i; j++) { 
                if (i <= j + arr[j] && dp[j] != INT_MAX) { 
                    dp[i] = min(dp[i], dp[j] + 1); 
                    break; 
                } 
            } 
        } 
        return dp[n - 1]; 
    } 
    

int main() {
	
int arr[] = {3, 4, 2, 1, 2, 1}, n =6;

cout<<minJumps(arr, n);
	

}

// most efficient
// O(n)
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int minJumps(int arr[], int n)
{

	if (n <= 1)
		return 0;

	if (arr[0] == 0)
		return -1;

	int maxReach = arr[0];
	int step = arr[0];
	int jump = 1;
	int i = 1;
	for (i = 1; i < n; i++) {
		if (i == n - 1)
			return jump;

		maxReach = max(maxReach, i + arr[i]);
		step--;

		if (step == 0) {
			jump++;

			if (i >= maxReach)
				return -1;

			step = maxReach - i;
		}
	}

	return -1;
}

int main()
{
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);

	cout << ("Minimum number of jumps to reach end is %d ",
			minJumps(arr, size));
	return 0;
}

