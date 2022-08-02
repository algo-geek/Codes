// efficient 1 // O(n^3)

#include<bits/stdc++.h>
using namespace std;

void find4Numbers(int A[], int n, int X)
{
	int l, r;
	sort(A, A+n);

	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i+1; j < n - 2; j++)
		{
			l = j + 1;
			r = n-1;

			while (l < r)
			{
				if( A[i] + A[j] + A[l] + A[r] == X)
				{
					cout << A[i]<<", " << A[j] <<", " << A[l] << ", " << A[r];
					l++; 
                    r--;
				}
				else if (A[i] + A[j] + A[l] + A[r] < X)
					l++;
				else
					r--;
			} 
		} 
	} 
}

int main()
{
	int A[] = {1, 4, 45, 6, 10, 12};
	int X = 21;
	int n = sizeof(A) / sizeof(A[0]);
	find4Numbers(A, n, X);
	return 0;
}

