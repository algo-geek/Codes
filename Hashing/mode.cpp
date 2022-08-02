// time: O(n+t) // space: O(n)
// Counting Sort technique
#include <bits/stdc++.h>
using namespace std;

void printMode(int a[], int n)
{
	int b[n];

	int max = *max_element(a, a + n);
	int t = max + 1;

	int count[t];
	for (int i = 0; i < t; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	int mode = 0;
	int k = count[0];
	for (int i = 1; i < t; i++) {
		if (count[i] > k) 
        {
			k = count[i];
			mode = i;
		}
	}

	cout << "mode = " << mode;
}

int main()
{
	int a[] = { 1, 4, 1, 2, 7, 1, 2, 5, 3, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	printMode(a, n);
	return 0;
}
