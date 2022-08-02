// O(n) time & space
#include<bits/stdc++.h>
using namespace std;

void findMode(int a[], int n)
{
	map<int, int> mp;
	int max = 0;
	int mode = 0;

	for(int i = 0; i < n; i++)
	{
		mp[a[i]]++;
	
		if (mp[a[i]] >= max)
		{
			max = mp[a[i]];
			mode = a[i];
		}
		cout << mode << " ";
	}
}
	
int main()
{
	int arr[] = { 2, 7, 3, 2, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findMode(arr, n);

	return 0;
}

