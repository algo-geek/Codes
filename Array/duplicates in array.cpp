// numbers in the array are from 0 to n-1
// input array can be used as a HashMap

1. Marking visits:
The array elements are between 0 and n-1.
For each element arr[i], take arr[i] % n to get the original value (because arr[index] may be modified in previous iterations).
Use that as an index and add n to the element at that index.
Every time you see a number x, you add n to arr[x].

2. Counting frequency:
After the first loop, elements in arr have been incremented multiple times by n depending on how many times their index (which corresponds to a number in the original array) appeared.
So arr[i] / n gives the count of how many times i appeared.
For example, if arr[i] was originally 2 and now is 2 + 2*n, then arr[i] / n = 2 which means the element i appeared twice.

3. Detecting duplicates:
If arr[i] / n is 2 or more, i appeared at least twice.
The function prints i as a repeating element.

#include <iostream>
using namespace std;

void printRepeating(int arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		int index = arr[i] % n;
		arr[index] += n;
	}

// check if freq is more than 1
	for (int i = 0; i < n; i++)
	{
		if ((arr[i] / n) >= 2)
			cout << i << " ";
	}
}

int main()
{
	int arr[] = { 1, 6, 3, 1, 3, 6, 6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "The repeating elements are: \n";
	printRepeating(arr, arr_size);
	return 0;
}
