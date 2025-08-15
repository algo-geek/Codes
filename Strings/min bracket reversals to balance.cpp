// min no of bracket reversals to make expression balanced
// naive- USING STACK // time & space: O(n)
//1.  If you see {, just push it onto the stack.
//2.  If you see }: If the stack has a {, pop it (they form a valid pair).
// else the stack is empty or doesn't have {, reverse the } into { and push. 
// This counts as one reversal, so increment ans.
//3.  If the stack size is odd, it's impossible to balance → return -1.
// Else, add stack size / 2 to ans:
// Every two unmatched brackets (like {{ or }}) can be balanced with 1 reversal.
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
