// 1
// difference between adjacent elements is 1
// return index of x, if multiple occurences, return 1st occurence index
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x)
{
	int i = 0;
	while (i<n)
	{
		if (arr[i] == x)
			return i;

		// Jump the difference between current array element and x
		i = i + abs(arr[i]-x);
	}

	cout << "number is not present!";
	return -1;
}

int main()
{
	int arr[] = {8 ,7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 3;
	cout << "Element " << x << " is present at index "
		<< search(arr,n,3);
	return 0;
}

// 2
// difference between adjacent elements is atmost k
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
	int i = 0;
	while (i < n)
	{
		if (arr[i] == x)
			return i;

		// We use max here to make sure that i moves at-least one step ahead.
		i = i + max(1, abs(arr[i]-x)/k);
	}

	cout << "number is not present!";
	return -1;
}

int main()
{
	int arr[] = {2, 4, 5, 7, 7, 6};
	int x = 6;
	int k = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Element " << x << " is present at index "
		<< search(arr, n, x, k);
	return 0;
}
