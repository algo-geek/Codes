// binary search solution
// 1. calculate:
// global min = min of 1st column elements in all rows
// global max = max of last column elements in all rows
// 2. total ele = n*m
// medPos = (n*m+1)/2 as it can be used for even and odd total ele
// 3. binary search ove range [global min, global max]
// at each step, count how many elements are ≤ mid using upper_bound on each row.

// time: O(n × log(m) × log(maxVal - minVal))
// upper_bound: log m (sorted rows)
// for all rows: n log m
// binary search loop: O(maxVal-minVal)


const int MAX = 100;
int matMed(int mat[][MAX], int r ,int c)
{
	int min = mat[0][0], max = mat[0][c-1];
	for (int i=1; i<r; i++)
	{
		if (mat[i][0] < min)
			min = mat[i][0];

		if (mat[i][c-1] > max)
			max = mat[i][c-1];
	}
	int medPos = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = (min + max) / 2;
		int midPos = 0;

		for (int i = 0; i < r; ++i)
			midPos += upper_bound(mat[i], mat[i]+c, mid) - mat[i];
		if (midPos < medPos)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}

int main()
{
	int r = 3, c = 5;
	int m[][MAX]= { {5,10,20,30,40}, {1,2,3,4,6}, {11,13,15,17,19} };
	cout << "Median is " << matMed(m, r, c) << endl;
	return 0;
}
