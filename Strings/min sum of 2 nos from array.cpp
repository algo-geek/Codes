// min sum of two numbers formed from array elements
// small numbers
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
	sort(arr, arr + n);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		// fill a and b with every alternate digit
		// of input array
		if (i & 1)
			a = a*10 + arr[i];
		else
			b = b*10 + arr[i];
	}

	return a + b;
}

int main()
{
	int arr[] = {6, 8, 4, 5, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sum is " << solve(arr, n); // 604 = 358 + 246
	return 0;
}

// for large numbers
#include <bits/stdc++.h>
using namespace std;

string solve2(int arr[], int n)
{
	sort(arr, arr + n);
	string a = "", b = "";
	// store in string alternatively
	for (int i = 0; i < n; i += 2)
	{
		a += (arr[i] + '0');
	}
	for (int i = 1; i < n; i += 2)
	{
		b += (arr[i] + '0');
	}
	int j = a.length() - 1;
	int k = b.length() - 1;
	int carry = 0;
	string ans = "";

	while (j >= 0 && k >= 0)
	{
		int sum = 0;
		sum += (a[j] - '0') + (b[k] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		j--;
		k--;
	}

// if string b is over and string a is left
	while (j >= 0)
	{
		int sum = 0;
		sum += (a[j] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		j--;
	}
	// if string a is over and string b is left
	while (k >= 0)
	{
		int sum = 0;
		sum += (b[k] - '0') + carry;
		ans += to_string(sum % 10);
		carry = sum / 10;
		k--;
	}
	// if carry is left
	if (carry)
	{
		ans += to_string(carry);
	}
	// to remove leading zeroes as they will be ahead of our sum
	while (!ans.empty() and ans.back() == '0')
		ans.pop_back();
	// reverse our final string because we were storing sum from left to right
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	int arr[] = {6, 8, 4, 5, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum is " << solve2(arr, n);
	return 0;
} 


