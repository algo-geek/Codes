// a[i]=i+1
// no duplicates
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high)
{
	if (high >= low) {
		int mid = low + (high - low) / 2;
		if (mid == arr[mid])
			return mid;
		int res = -1;
		if (mid + 1 <= arr[high])
			res = binarySearch(arr, (mid + 1), high);
		if (res != -1)
			return res;
		if (mid - 1 >= arr[low])
			return binarySearch(arr, low, (mid - 1));
	}

	return -1;
}

int main()
{
	int arr[10] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Fixed Point is " << binarySearch(arr, 0, n - 1);
	return 0;
}

// duplicates allowed
#include <bits/stdc++.h>
using namespace std;

int magicIndex(int* arr, int start, int end)
{
	if (start > end)
		return -1;

	int midIndex = (start + end) / 2;
	int midValue = arr[midIndex];

	if (midIndex == midValue)
		return midIndex;

	// Search on Left side
	int left = magicIndex(arr, start, min(midValue,
									midIndex - 1));

	// If Found on left side, return.
	if (left >= 0)
		return left;

	return magicIndex(arr, max(midValue, midIndex + 1),
												end);
}

int main()
{
	int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7,
								9, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = magicIndex(arr, 0, n - 1);
	if (index == -1)
		cout << "No Magic Index";
	else
		cout << "Magic Index is : " << index;
	return 0;
}


