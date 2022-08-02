// min swaps to sort array
// naive // O(n^2)
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int indexOf(vector<int> &arr, int ele)
{
	for(int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == ele)
		{
			return i;
		}
	}
	return -1;
}

int minSwaps(vector<int> arr, int N)
{
	int ans = 0;
	vector<int> temp(arr.begin(),arr.end());
	sort(temp.begin(),temp.end());
	
	for(int i = 0; i < N; i++)
	{
		if (arr[i] != temp[i])
		{
			ans++;

			swap(arr, i, indexOf(arr, temp[i]));
		}
	}
	return ans;
}

int main()
{

	vector<int> a = {101, 758, 315, 730,
				472, 619, 460, 479};
	
	int n = a.size();
	
	cout << minSwaps(a, n);
}


//  efficient // O(n log n)
#include<bits/stdc++.h>
using namespace std;


int minSwaps(int arr[], int n)
{
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	sort(arrPos, arrPos + n);
	vector<bool> vis(n, false);

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of node in this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}

	return ans;
}

int main()
{
	int arr[] = {1, 5, 4, 3, 2};
	int n = (sizeof(arr) / sizeof(int));
	cout << minSwaps(arr, n);
	return 0;
}
