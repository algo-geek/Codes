// time: O(k) // space: O(1)
#include <bits/stdc++.h>
using namespace std;

int find(int A[], int B[], int m, int n, int k_req)
{
	int k = 0, i = 0, j = 0;

	while(i < m && j < n)
	{
		if(A[i] < B[j])
		{
			k++;
			if(k == k_req)
				return A[i];
			i++;
		}
		else
		{
			k++;
			if(k == k_req)
				return B[j];
			j++;
		}
	}

	while(i < m)
	{
		k++;
		if(k == k_req)
			return A[i];
		i++;
	}

	while(j < n)
	{
		k++;
		if(k == k_req)
			return B[j];
		j++;
	}
}

int main()
{
	int A[5] = { 2, 3, 6, 7, 9 };
	int B[4] = { 1, 4, 8, 10 };
	int k = 5;
	
	cout << find(A, B, 5, 4, k);
	
	return 0;
}

