
// prod[i] is equal to the product of all the elements of arr[] except arr[i] // without using division
// time : O(n) // space: O(1)

// 1
#include <bits/stdc++.h>
using namespace std;

void productArray(int arr[], int n)
{

	// Base case
	if (n == 1) {
		cout << 0;
		return;
	}
	vector<int>v;
    int p=1;
	int i, j;

    // left product
	for (i = 0; i < n; i++)
	{
        p*=arr[i];
        v.push_back(p);
    }

    p=1;
    // right product
    // left*right product
	for (i = n - 1; i > 0; i--)
	{
        v[i]=v[i-1]*p;
        p*=arr[i];
    }
    v[0]=p;

	for (i = 0; i < n; i++)
		cout << v[i] << " ";

	return;
}

int main()
{
	int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The product array is: \n";
	productArray(arr, n);
}


//2
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
	int prod = 1;
	for (int i = 0; i < n; i++)
		prod *= arr[i];

	for (int i = 0; i < n; i++) {
		cout << (int)(prod * pow(arr[i], -1)) << ' ';
	}
}

int main()
{
	int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	solve(arr, n);
	return 0;
}

// 3
#include <bits/stdc++.h>
using namespace std;

// epsilon value to maintain precision
#define EPS 1e-9

void productPuzzle(int a[], int n)
{
	long double sum = 0;
	for (int i = 0; i < n; i++)
		sum += (long double)log10(a[i]);

	for (int i = 0; i < n; i++)
		cout << (int)(EPS + pow((long double)10.00, sum - log10(a[i])))<< " ";
}

int main()
{
	int a[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "The product array is: \n";
	productPuzzle(a, n);
	return 0;
}
