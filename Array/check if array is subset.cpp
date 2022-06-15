// naive // O(n^2)
#include <bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int arr2[],
			int m, int n)
{
	int i = 0, j = 0;

	if (m < n)
		return 0;

	sort(arr1, arr1 + m);
	sort(arr2, arr2 + n);

	while (i < n && j < m)
	{
		if (arr1[j] < arr2[i])
			j++;
		else if (arr1[j] == arr2[i])
		{
			j++;
			i++;
		}

		else if (arr1[j] > arr2[i])
			return 0;
	}

	return (i < n) ? false : true;
}

int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[] ");

	return 0;
}

// efficient // O(n) time & space
#include <bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int n, int arr2[], int m)
{

	unordered_set<int> hashset;

	for (int i = 0; i < m; i++)
	{
		hashset.insert(arr1[i]);
	}


	for (int i = 0; i < n; i++) {
		if (hashset.find(arr2[i]) == hashset.end())
			return false;
	}
	return true;
}


int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, n, arr2, m))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}


