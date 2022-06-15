// naive
#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int n){
    int temp[n],i=0;
    
    for(int j=0;j<n;j++)
        if(arr[j]==0)
            temp[i++]=arr[j];
    for(int j=0;j<n;j++)
        if(arr[j]==1)
            temp[i++]=arr[j];
    for(int k=0;k<n;k++)
        if(arr[k]==2)
            temp[i++]=arr[k];
    for(int j=0;j<n;j++)
        arr[j]=temp[j];
    
}

int main() {
	
    int arr[]={0,1,1,2,0,1,1,2};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";
}

// keep count of 0s, 1, 2s
// time: O(n) // space: O(1)
#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void sortArr(int arr[], int n)
{
	int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

	for (i = 0; i < n; i++) {
		switch (arr[i]) {
		case 0:
			cnt0++;
			break;
		case 1:
			cnt1++;
			break;
		case 2:
			cnt2++;
			break;
		}
	}

	i = 0;

	while (cnt0 > 0) {
		arr[i++] = 0;
		cnt0--;
	}

	while (cnt1 > 0) {
		arr[i++] = 1;
		cnt1--;
	}

	while (cnt2 > 0) {
		arr[i++] = 2;
		cnt2--;
	}

	printArr(arr, n);
}

int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(int);

	sortArr(arr, n);

	return 0;
}


// dnf
#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int n){
    int l=0,h=n-1,mid=0;
    while(mid<=h){
        switch(arr[mid]){
            case 0:
                swap(arr[l],arr[mid]);
                l++;
				mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[h],arr[mid]);
                h--;
                break;
        }
    }
    
}

int main() {
	
    int arr[]={0,1,1,2,0,1,1,2};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,n);
	
	for(int x:arr)
	    cout<<x<<" ";
}