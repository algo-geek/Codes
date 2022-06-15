// Given a range [lowVal, highVal], partition the array around the range such that array is divided in three parts. 
// using dhf algo of quicksort
// O(n) time
#include<iostream>
using namespace std;

void threeWayPartition(int arr[], int n, int lowVal, int highVal)
{
	int start = 0, end = n-1;

	for (int i=0; i<=end;)
	{
		if (arr[i] < lowVal)
		{
		//if i and start are same in that case we can't swap
		//swap only if i is greater than start
		    if(i==start)
		    {
			    start++;
			    i++;
		    }
		    else
		    {
                swap(arr[i++], arr[start++]);
            }
		}

		else if (arr[i] > highVal)
			swap(arr[i], arr[end--]);

		else
			i++;
	}
}

int main()
{
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,
				98, 3, 1, 32};
	int n = sizeof(arr)/sizeof(arr[0]);

	threeWayPartition(arr, n, 10, 20);

	cout << "Modified array \n";
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}
