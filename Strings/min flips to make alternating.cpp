// min no of flips to make binary string alternating
// O(n) time // O(1) space

#include <bits/stdc++.h>
using namespace std;

char flip(char ch) 
{ 
    return (ch == '0') ? '1' : '0'; 
}

int getFlipWithStartingCharcter(string str, char expected)
{
	int flipCount = 0;
	for (int i = 0; i < str.length(); i++) 
    {
		if (str[i] != expected)
			flipCount++;

		expected = flip(expected);
	}
	return flipCount;
}

int minFlipToMakeStringAlternate(string str)
{
	// 2 possibilities- either start the string with 0 or with 1 and keep alternating
	return min(getFlipWithStartingCharcter(str, '0'),
			getFlipWithStartingCharcter(str, '1'));
}

int main()
{
	string str = "0001010111";
	cout << minFlipToMakeStringAlternate(str);
	return 0;
}

