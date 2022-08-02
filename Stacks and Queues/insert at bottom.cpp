// O(n) time & space

// stack
#include <bits/stdc++.h>
using namespace std;

void insertToBottom(stack<int> S, int N)
{
	stack<int> temp;

	while (!S.empty())
     {
		temp.push(S.top());
		S.pop();
	}

	S.push(N);

	while (!temp.empty()) 
    {
		S.push(temp.top());
		temp.pop();
	}

	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}

int main()
{
	stack<int> S;
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);
	S.push(1);

	int N = 7;

	insertToBottom(S, N);

	return 0;
}

// recursion
#include <bits/stdc++.h>
using namespace std;

stack<int> recur(stack<int> S, int N)
{
	if (S.empty())
		S.push(N);

	else 
    {
		int X = S.top();
		S.pop();

		// Recurse with remaining elements
		S = recur(S, N);

		// Push the previous top element again
		S.push(X);
	}
	return S;
}

void insertToBottom(
	stack<int> S, int N)
{
	S = recur(S, N);

	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}

int main()
{
	stack<int> S;
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);
	S.push(1);

	int N = 7;

	insertToBottom(S, N);

	return 0;
}
