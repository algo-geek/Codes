// O(n)
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findMissing(int arr[], int n)
{
	int a,d,l,s,i,sum=0,missingnumber;
	a=arr[0];
	l=arr[n-1];

	
	if((a+l)%2==0)
	{
		s = (a+l)/2;
		s = s*(n+1);
	}
	else
	{
		s = (n+1)/2;
		s = (a+l)*s;

	}

	for(i=0;i<=n-1;i++)
	{
		sum = sum + arr[i];
	}

	missingnumber=s-sum;

	return missingnumber;

}

int main()
{
	int arr[] = {2, 4, 8, 10, 12, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The missing element is "
		<< findMissing(arr, n);
	return 0;
}

// binary search // O( log n)
#include<bits/stdc++.h>
using namespace std;

int findMissingUtil(int arr[], int low, int high, int diff)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		// if mid == (nth position of element in AP)-1
		// the missing element will exist in right half
		if ((arr[mid] - arr[0]) / diff == mid)
			low = mid + 1;
		else
		// the missing element will exist in left half
			high = mid - 1;
	}
	// after breaking out of binary search loop the missing element
  	// will exist between high and low
	return arr[high] + diff;
}


int findMissing(int arr[], int n)
{
    // common difference
	int diff = (arr[n - 1] - arr[0]) / n;

	return findMissingUtil(arr, 0, n - 1, diff);
}

int main()
{
	int arr[] = {2, 4, 8, 10, 12, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The missing element is "
		<< findMissing(arr, n);
	return 0;
}
