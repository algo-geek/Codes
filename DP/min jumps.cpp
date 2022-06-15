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