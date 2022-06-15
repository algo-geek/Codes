//to find the maximum count of consecutive substrings 
// such that all the substrings are balanced 
// i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.

#include <bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n)
{
	int count0 = 0, count1 = 0;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			count0++;
		}
		else {
			count1++;
		}
		if (count0 == count1) {
			cnt++;
		}
	}

	if (count0!=count1) {
		return -1;
	}

	return cnt;
}

int main()
{
	string str = "0100110101";
	int n = str.length();

	cout << maxSubStr(str, n);

	return 0;
}

// 01 0011 01 01 are the substrings
// no of substrings= 4