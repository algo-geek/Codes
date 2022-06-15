
// naive
#include <bits/stdc++.h>
using namespace std;

void partition(int arr[], int l, int h, int p)
{
    int temp[h-l+1],index=0;
    // elements smaller than pivot
    for(int i=l;i<=h;i++)
        if(arr[i]<=arr[p] && i != p)
            {
                temp[index]=arr[i];
                index++;
            }
    temp[index++] = arr[p];
     // elements greater than pivot
     // res=l+idx-1;
    for(int i=l;i<=h;i++)
        if(arr[i]>arr[p])
            {
                temp[index]=arr[i];
                index++;
            }
    for(int i=l;i<=h;i++)
        arr[i]=temp[i-l];
}
 
int main() {
	
    int arr[]={5,13,6,9,12,11,8};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	partition(arr,0,n-1,3);
	
	for(int x: arr)
	    cout<<x<<" ";
}

// lomuto
#include <bits/stdc++.h>
using namespace std;

int iPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
 
int main() {
	
    int arr[]={10,80,30,90,40,50,70};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	iPartition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}

// hoare
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{   
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}
 
int main() {
	
    int arr[]={5,3,8,4,2,7,1,10};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	partition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}