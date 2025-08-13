// use a temp atck to be returned with sorted items
// Pop an element from the input stack (tmp).
// While the temporary stack’s top is greater than tmp, move elements back to the input stack.
// Push tmp into its correct position in tmpStack (which remains sorted).

#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &input)
{
	stack<int> tmpStack;

	while (!input.empty())
	{
		int tmp = input.top();
		input.pop();

		while (!tmpStack.empty() && tmpStack.top() > tmp)
		{
			input.push(tmpStack.top());
			tmpStack.pop();
		}

		tmpStack.push(tmp);
	}

	return tmpStack;
}

// main function
int main()
{
	stack<int> input;
	input.push(34);
	input.push(3);
	input.push(31);
	input.push(98);
	input.push(92);
	input.push(23);

	stack<int> tmpStack = sortStack(input);
	cout << "Sorted numbers are:\n";

	while (!tmpStack.empty())
	{
		cout << tmpStack.top()<< " ";
		tmpStack.pop();
	}
}
