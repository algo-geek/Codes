
#include <bits/stdc++.h>
using namespace std;

struct Interval
{
	int s;
	int e;
};

bool comp(Interval a, Interval b)
{
	return a.s < b.s;
}

int kthSmallestNum(vector<Interval> merged, int k)
{
	int n = merged.size();
	for (int j = 0; j < n; j++)
	{
		if (k <= abs(merged[j].e -merged[j].s + 1))
			return (merged[j].s + k - 1);

		k = k - abs(merged[j].e -merged[j].s + 1);
	}

	if (k)
		return -1;
}

void mergeIntervals(vector<Interval> &merged,Interval arr[], int n)
{
	sort(arr, arr + n, comp);
	merged.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		Interval prev = merged.back();
		Interval curr = arr[i];
        // if overlapping
		if ((curr.s >= prev.s &&
			curr.s <= prev.e) &&
			(curr.e > prev.e))

			merged.back().e = curr.e;
// if non-overlapping
		else
		{
			if (curr.s > prev.e)
				merged.push_back(curr);
		}
	}
}

int main()
{
	Interval arr[] = {{2, 6}, {4, 7}};
	int n = sizeof(arr)/sizeof(arr[0]);
	int query[] = {5, 8};
	int q = sizeof(query)/sizeof(query[0]);

	vector<Interval>merged;
	mergeIntervals(merged, arr, n);

	for (int i = 0; i < q; i++)
		cout << kthSmallestNum(merged, query[i])
			<< endl;

	return 0;
}
