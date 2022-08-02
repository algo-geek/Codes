// min no of bracket reversals to make expression balanced
// naive // time & space: O(n)
#include <iostream>
using namespace std;
#include <stack>

int countMinReversals(string str)
{
	stack<char> st;
	int ans = 0;

	for (int i = 0; i < str.size(); i++) 
    {
		if (str[i] == '{')
			st.push(str[i]);
		else
        {	
			if (!st.empty())
				st.pop();
			else {
				st.push('{');
				ans++;
			}
		}
	}
	// if stack size is odd return -1.
	if (st.size() % 2 != 0)
		return -1;

	ans += st.size() / 2;

	return ans;
}

int main()
{
	string expr = "{{{{}}";
	cout << countMinReversals(expr);
	return 0;
}

// efficient // time: O(n) // space: O(1)
#include <bits/stdc++.h>
using namespace std;

int countMinReversals(string s)
{
	int temp = 0, res = 0, n = s.size();
	if (n % 2 != 0)
		return -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			temp++;
		else {
			if (temp == 0) {
				res++;
				temp++;
			}
			else
				temp--;
		}
	}
	if (temp > 0)
		res += temp / 2;
	return res;
}

int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}
