// naive // O(n^3)
#include <bits/stdc++.h>
using namespace std;

void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

int longestPalSubstr(string str)
{
	int n = str.size();

	// All substrings of length 1 are palindromes
	int maxLength = 1, start = 0;

	// to mark start and end index of substring
	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			int flag = 1;

			// Check if palindrome
			for (int k = 0; k < (j - i + 1) / 2; k++)
				if (str[i + k] != str[j - k])
					flag = 0;

			// if Palindrome
			if (flag && (j - i + 1) > maxLength) {
				start = i;
				maxLength = j - i + 1;
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	return maxLength;
}

int main()
{
	string str;
    cin >> str;
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}

// efficient // O(n^2)
#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(string str)
{
	int n = str.size(); 

     // if string is empty then size will be 0.
	// if n==1 then, answer will be 1(single character will always palindrome)
	if (n < 2)
		return n; 
   
	int maxLength = 1, start=0;
	int low, high;
	for (int i = 0; i < n; i++) {
		low = i - 1;
		high = i + 1;
		while ( high < n && str[high] == str[i]) 							
			high++;
	
		while ( low >= 0 && str[low] == str[i]) 			
			low--;
	
		while (low >= 0 && high < n && str[low] == str[high]){
			low--;
			high++;
		}

		int length = high - low - 1;
		if (maxLength < length) {
			maxLength = length;
			start=low+1;
		}
	}
	
	cout<<"Longest palindrome substring is: ";
	cout<<str.substr(start,maxLength);
	return maxLength;
}

int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: " << longestPalSubstr(str)
		<< endl;
	return 0;
}

