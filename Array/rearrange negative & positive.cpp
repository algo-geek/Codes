// negatives and positives appear alternately

#include <bits/stdc++.h>
using namespace std;

// modification of move all negatives to beginning of array
// partition with 0 as pivot
void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}

    int pos=j, neg=0;
    while(pos<n && neg<pos && arr[neg]<0)
    {
        swap(arr[neg], arr[pos]);
        pos++;
        neg+=2;
    }
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}