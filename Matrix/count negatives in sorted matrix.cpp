// O(n+m)

#include <bits/stdc++.h>
using namespace std;

int countNegative(int M[][4], int n, int m)
{
	int count = 0;
	int i = 0;
	int j = m - 1;

	while (j >= 0 && i < n) 
    {
		if (M[i][j] < 0) 
        {
		
			count += j + 1;

			i += 1;
		}


		else
			j -= 1;
	}

	return count;
}

int main()
{
	int M[3][4] = { { -3, -2, -1, 1 },
					{ -2, 2, 3, 4 },
					{ 4, 5, 7, 8 } };

	cout << countNegative(M, 3, 4);

	return 0;
}
