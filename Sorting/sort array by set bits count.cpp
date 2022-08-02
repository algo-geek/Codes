// naive // time: O(n^2)
// using insertion sort
#include <bits/stdc++.h>
using namespace std;

int countBits(int a)
{
	int count = 0;
	while (a) {
		if (a & 1)
			count += 1;
		a = a >> 1;
	}
	return count;
}

void insertionSort(int arr[], int aux[], int n)
{
	for (int i = 1; i < n; i++) {
		int key1 = aux[i];
		int key2 = arr[i];
		int j = i - 1;

		while (j >= 0 && aux[j] < key1) {
			aux[j + 1] = aux[j];
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		aux[j + 1] = key1;
		arr[j + 1] = key2;
	}
}

void sortBySetBitCount(int arr[], int n)
{
	int aux[n];
	for (int i = 0; i < n; i++)
		aux[i] = countBits(arr[i]);

	insertionSort(arr, aux, n);
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	printArr(arr, n);
	return 0;
}



// efficient 1
// time: O(n log n) // space: O(n)
#include <bits/stdc++.h>
using namespace std;

void sortArr(int arr[], int n)
{
	multimap<int, int> map;

	for (int i = 0; i < n; i++) {
		int count = 0;
		int k = arr[i];

		// Counting no of setBits in arr[i]
		while (k) {
			k = k & k - 1;
			count++;
		}

		// The count is subtracted from 32
		// because the result needs
		// to be in descending order
		map.insert(make_pair(32 - count, arr[i]));
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		cout << (*it).second << " ";
	}
}

int main()
{
	int arr[] = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortArr(arr, n);

	return 0;
}

// efficient 2
// space: O(1)
// using comparator of sort
#include <bits/stdc++.h>
using namespace std;

int countBits(int a)
{
	int count = 0;
	while (a) {
		if (a & 1)
			count += 1;
		a = a >> 1;
	}
	return count;
}

int cmp(int a, int b)
{
	int count1 = countBits(a);
	int count2 = countBits(b);

	if (count1 <= count2)
		return false;
	return true;
}

void sortBySetBitCount(int arr[], int n)
{
	stable_sort(arr, arr + n, cmp);
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	printArr(arr, n);
	return 0;
}

