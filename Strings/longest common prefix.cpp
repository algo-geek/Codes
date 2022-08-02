
// time: O(n*m), n = no of strings, m = length of largest string
// space: O(length of prefix)
//1. word by word mattching
#include<bits/stdc++.h>
using namespace std;

string commonPrefixUtil(string& str1, string& str2)
{
	string result = "";
	int len = min(str1.length(), str2.length());

	for (int i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
			break;
		result += str1[i];
	}

	return (result);
}

string commonPrefix (string arr[], int n)
{
	string prefix = arr[0];

	for (int i=1; i < n; i++)
		prefix = commonPrefixUtil(prefix, arr[i]);

	return (prefix);
}

int main()
{
	string arr[] = {"geeksforgeeks", "geeks",
					"geek", "geezer"};
	int n = sizeof(arr) / sizeof(arr[0]);

	string ans = commonPrefix(arr, n);

	if (ans.length())
		printf ("The longest common prefix is - %s",
				ans.c_str());
	else
		printf("There is no common prefix");

	return (0);
}

// 2. character by character matching
#include<bits/stdc++.h>
using namespace std;

int findMinLength(string arr[], int n)
{
	int min = arr[0].length();

	for (int i=1; i<n; i++)
		if (arr[i].length() < min)
			min = arr[i].length();

	return(min);
}


string commonPrefix(string arr[], int n)
{
	int minlen = findMinLength(arr, n);

	string result; 
	char current; 

	for (int i=0; i<minlen; i++)
	{
		current = arr[0][i];

		for (int j=1 ; j<n; j++)
			if (arr[j][i] != current)
				return result;

		result.push_back(current);
	}

	return (result);
}

int main()
{
	string arr[] = {"geeksforgeeks", "geeks",
					"geek", "geezer"};
	int n = sizeof (arr) / sizeof (arr[0]);

	string ans = commonPrefix (arr, n);

	if (ans.length())
		cout << "The longest common prefix is "
			<< ans;
	else
		cout << "There is no common prefix";
	return (0);
}

// space: o(1)
// time: O(n*m), n = no of strings, m = length of smallest string
#include <bits/stdc++.h>
using namespace std;

int shortest_string(string s[], int n)
{
	int minlength = INT_MAX, min_index;
	for (int i = 0; i < n; i++) {
		if (s[i].length() < minlength) {
			minlength = s[i].length();
			min_index = i;
		}
	}
	return min_index;
}

string findprefix(string s[], int n)
{
	int shortest_string_index = shortest_string(s, n);

	while (s[shortest_string_index].length() > 0) {

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (s[i].find(s[shortest_string_index]) == 0) {
				count++;
			}
		}
		if (count == n) {
			cout << "longest common prefix is: " << endl;
			return s[shortest_string_index];
			break;
		}
		s[shortest_string_index].pop_back();
	}

	return "no common prefix among all strings";
}
// driver code
int main()
{
	string s[]
		= { "geeksforgeeks", "geeks", "geek", "geezer" };
	int n = sizeof(s) / sizeof(s[0]);
	cout << findprefix(s, n);
	return 0;
}

