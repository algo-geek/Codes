// a[i]=i+1
// no duplicates
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid)
            return mid;
        else if (arr[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // If no fixed point is found
    return -1;
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
	int left = magicIndex(arr, start, min(midValue, midIndex - 1));

	// If Found on left side, return.
	if (left >= 0)
		return left;

	return magicIndex(arr, max(midValue, midIndex + 1), end);
}


