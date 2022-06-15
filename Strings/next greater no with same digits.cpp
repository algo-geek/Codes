// naive // O(n log n)
#include <bits/stdc++.h>
using namespace std;


void findNext(char number[], int n)
{
	int i, j;
	for (i = n-1; i > 0; i--)
		if (number[i] > number[i-1])
		break;

	if (i==0)
	{
		cout << "Next number is not possible";
		return;
	}

	int x = number[i-1], smallest = i;
	for (j = i+1; j < n; j++)
		if (number[j] > x && number[j] < number[smallest])
			smallest = j;

	swap(number[smallest], number[i-1]);

	sort(number + i, number + n);

	cout << "Next number with same set of digits is " << number;

	return;
}

int main()
{
	char digits[] = "534976";
	int n = strlen(digits);
	findNext(digits, n);
	return 0;
}

// efficient // O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> arr)
{
	if (n == 1)
		return arr;

	int i = 0;
	for (i = n - 1; i > 0; i--) {
		if (arr[i] > arr[i - 1])
			break;
	}

	if (i != 0) {
		for (int j = n - 1; j >= i; j--) {
			if (arr[i - 1] < arr[j]) {
				swap(arr[i - 1], arr[j]);
				break;
			}
		}

        reverse(arr.begin() + i, arr.end());
	}
	

	return arr;
}

int main()
{
	int n = 6;
	vector<int> v{ 5,3,4,9,7,6 };
	vector<int> res;
	res = nextPermutation(n, v);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}
