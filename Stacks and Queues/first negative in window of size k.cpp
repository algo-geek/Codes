// deque
#include <bits/stdc++.h>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k)
{
	deque<int> D;
	int i;
	for (i = 0; i < k; i++)
		if (arr[i] < 0)
			D.push_back(i);

	
	for (i = k ; i < n; i++)
	{
		if (!D.empty())
			cout << arr[D.front()] << " ";
		else
			cout << "0" << " ";

		while ( (!D.empty()) && D.front() <= (i - k))
			D.pop_front(); 

		if (arr[i] < 0)
			D.push_back(i);
	}

	if (!D.empty())
		cout << arr[D.front()] << " ";
	else
		cout << "0" << " ";	
	
}

int main()
{
	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, n, k);
	return 0;
}

// efficient
#include <iostream>
using namespace std;

void printFirstNegativeInteger(int arr[], int k, int n)
{
	int firstNegativeIndex = 0;
	int firstNegativeElement;
	
	
	for(int i = k - 1; i < n; i++)
	{
	
		// skip out of window and positive elements
		while( (firstNegativeIndex < i ) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0) )
		{
			firstNegativeIndex ++;
		}
		
		// check if a negative element is found, otherwise use 0
		if(arr[firstNegativeIndex] < 0)
		{
			firstNegativeElement = arr[firstNegativeIndex];
		}
		else
		{
			firstNegativeElement = 0;
		}
		cout<<firstNegativeElement << " ";
	}
	
}

int main()
{
	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, k, n);
}

