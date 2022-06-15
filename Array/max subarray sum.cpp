//naive
#include <iostream>
#include <cmath>
using namespace std;


int maxSum(int arr[], int n)
{
	int res = arr[0];

	for(int i = 0; i < n; i++)
	{
		int curr = 0;

		for(int j = i; j < n; j++)
		{
			curr = curr + arr[j];

			res = max(res, curr);
		}
	}
	
	return res;
}



int main() {
	
     int arr[] = {1, -2, 3, -1, 2}, n = 5;

     cout<<maxSum(arr, n);
    
}

//efficient
#include <iostream>
#include <cmath>
using namespace std;


int maxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}



int main() {
	
     int arr[] = {1, -2, 3, -1, 2}, n = 5;

     cout<<maxSum(arr, n);
    
}

// to get subarray
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
	start =0, end = 0, s=0;

	for (int i=0; i< size; i++ )
	{
		max_ending_here += a[i];

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is "
		<< max_so_far << endl;
	cout << "Starting index "<< start
		<< endl << "Ending index "<< end << endl;

	return max_so_far;
}

int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	return 0;
}
