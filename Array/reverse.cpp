// time: O(n)

//iterative 
#include <iostream>
#include <cmath>
using namespace std;

 void reverse(int arr[], int n)
{
	int low = 0, high = n - 1;

	while(low < high)
	{
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;

		low++;
		high--;
	}
}

    
int main() {
	
      int arr[] = {10, 5, 7, 30}, n = 4;

      cout<<"Before Reverse"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       reverse(arr, n);

       cout<<"After Reverse"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
    
}

//recursive
#include <bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int start, int end)
{
	if (start >= end)
	return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	rvereseArray(arr, start + 1, end - 1);
}	

void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};

	printArray(arr, 6);
	rvereseArray(arr, 0, 5);
	
	cout << "Reversed array is" << endl;
	printArray(arr, 6);
	
	return 0;
}
