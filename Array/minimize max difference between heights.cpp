// We need to either increase or decrease the height of every tower by k 
// find min difference between max and min heights

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
	sort(arr, arr + n);
    // Maximum possible height difference
	int ans = arr[n - 1] - arr[0]; 

	int smallest, largest;
	smallest = arr[0];
	largest = arr[n - 1];

	for (int i = 1; i < n; i++) {
        // if on subtracting k we get negative then continue
		if(arr[i] - k < 0) 
		continue;
        
		// Minimum element when we add k to whole array
		smallest = min(arr[0] + k,arr[i] - k); 

		// Maximum element when we subtract k from whole array
		largest = max(arr[i - 1] + k, arr[n - 1] - k); 

		ans = min(ans, largest - smallest);
	}
	return ans;
}

int main()
{
	int k = 6, n = 6;
	int arr[n] = { 7, 4, 8, 8, 8, 9 };
	int ans = getMinDiff(arr, n, k);
	cout << ans;
}

// variation- minimize the difference between max and min
// O(n)
#include <bits/stdc++.h>
using namespace std;

int minimizeDiff(int* arr, int n, int k)
{
	int max = *(max_element(arr, arr + n));
	int min = *(min_element(arr, arr + n));

	if ((max - min) <= k) {
		return (max - min);
	}

	int avg = (max + min) / 2;

	for (int i = 0; i < n; i++) {
		if (arr[i] > avg)
			arr[i] -= k;
		else
			arr[i] += k;
	}

	max = *(max_element(arr, arr + n));
	min = *(min_element(arr, arr + n));

	return (max - min);
}

int main()
{
	int arr[] = { 3, 16, 12, 9, 20 };
	int n = 5;
	int k = 3;

	cout << "Max height difference = "
		<< minimizeDiff(arr, n, k) << endl;

	return 0;
}
