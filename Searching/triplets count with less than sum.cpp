// count triplets less than given sum // o(n^2)
#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
	sort(arr, arr+n);
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		int j = i + 1, k = n - 1;

		while (j < k)
		{
			if (arr[i] + arr[j] + arr[k] >= sum)
				k--;

			else
			{
				// For current i and j, there
				// can be total k-j third elements.
				ans += (k - j);
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	int arr[] = {5, 1, 3, 4, 7};
	int n = sizeof arr / sizeof arr[0];
	int sum = 12;
	cout << countTriplets(arr, n, sum) << endl;
	return 0;
}
