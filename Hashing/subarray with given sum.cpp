// 1
#include <bits/stdc++.h>
using namespace std;

bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++)
    {   
        if(pre_sum==sum)
            return true;
        pre_sum += arr[i];
        if(s.find(pre_sum-sum) != s.end())
          return true;
        s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum=22;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << isSum(arr, n, sum);
}


// negatives not allowed
// naive
#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
	int curr_sum, i, j;

	for (i = 0; i < n; i++) {
		curr_sum = arr[i];

		for (j = i + 1; j <= n; j++) {
			if (curr_sum == sum) {
				cout << "Sum found between indexes "
					<< i << " and " << j - 1;
				return 1;
			}
			if (curr_sum > sum || j == n)
				break;
			curr_sum = curr_sum + arr[j];
		}
	}

	cout << "No subarray found";
	return 0;
}

int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}

// efficient
#include <iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
	int curr_sum = arr[0], start = 0, i;

	for (i = 1; i <= n; i++) {
		while (curr_sum > sum && start < i - 1) {
			curr_sum = curr_sum - arr[start];
			start++;
		}

		if (curr_sum == sum) {
			cout << "Sum found between indexes "
				<< start << " and " << i - 1;
			return 1;
		}

		if (i < n)
			curr_sum = curr_sum + arr[i];
	}

	cout << "No subarray found";
	return 0;
}

int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}


// negatives allowed
// naive
#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
	int curr_sum, i, j;

	for (i = 0; i < n; i++) {
		curr_sum = arr[i];

		for (j = i + 1; j <= n; j++) {
			if (curr_sum == sum) {
				cout << "Sum found between indexes "
					<< i << " and " << j - 1;
				return 1;
			}
			if (j == n)
				break;
			curr_sum = curr_sum + arr[j];
		}
	}

	cout << "No subarray found";
	return 0;
}

int main()
{
	int arr[] = { 10, 2, -2, -20, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = -10;
	subArraySum(arr, n, sum);
	return 0;
}

// efficient
